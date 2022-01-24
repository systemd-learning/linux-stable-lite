/* SPDX-License-Identifier: LGPL-2.1 OR MIT */
/*
 * rseq.h
 *
 * (C) Copyright 2016-2018 - Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 */

#ifndef RSEQ_H
#define RSEQ_H

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <signal.h>
#include <sched.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "rseq-abi.h"

/*
 * Empty code injection macros, override when testing.
 * It is important to consider that the ASM injection macros need to be
 * fully reentrant (e.g. do not modify the stack).
 */
#ifndef RSEQ_INJECT_ASM
#define RSEQ_INJECT_ASM(n)
#endif

#ifndef RSEQ_INJECT_C
#define RSEQ_INJECT_C(n)
#endif

#ifndef RSEQ_INJECT_INPUT
#define RSEQ_INJECT_INPUT
#endif

#ifndef RSEQ_INJECT_CLOBBER
#define RSEQ_INJECT_CLOBBER
#endif

#ifndef RSEQ_INJECT_FAILED
#define RSEQ_INJECT_FAILED
#endif

extern __thread struct rseq_abi __rseq_abi;
extern int __rseq_handled;

static inline struct rseq_abi *rseq_get_abi(void)
{
	return &__rseq_abi;
}

#define rseq_likely(x)		__builtin_expect(!!(x), 1)
#define rseq_unlikely(x)	__builtin_expect(!!(x), 0)
#define rseq_barrier()		__asm__ __volatile__("" : : : "memory")

#define RSEQ_ACCESS_ONCE(x)	(*(__volatile__  __typeof__(x) *)&(x))
#define RSEQ_WRITE_ONCE(x, v)	__extension__ ({ RSEQ_ACCESS_ONCE(x) = (v); })
#define RSEQ_READ_ONCE(x)	RSEQ_ACCESS_ONCE(x)

#define __rseq_str_1(x)	#x
#define __rseq_str(x)		__rseq_str_1(x)

#define rseq_log(fmt, args...)						       \
	fprintf(stderr, fmt "(in %s() at " __FILE__ ":" __rseq_str(__LINE__)"\n", \
		## args, __func__)

#define rseq_bug(fmt, args...)		\
	do {				\
		rseq_log(fmt, ##args);	\
		abort();		\
	} while (0)

#if defined(__x86_64__) || defined(__i386__)
#include <rseq-x86.h>
#elif defined(__ARMEL__)
#include <rseq-arm.h>
#elif defined (__AARCH64EL__)
#include <rseq-arm64.h>
#elif defined(__PPC__)
#include <rseq-ppc.h>
#elif defined(__mips__)
#include <rseq-mips.h>
#elif defined(__s390__)
#include <rseq-s390.h>
#else
#error unsupported target
#endif

/*
 * Register rseq for the current thread. This needs to be called once
 * by any thread which uses restartable sequences, before they start
 * using restartable sequences, to ensure restartable sequences
 * succeed. A restartable sequence executed from a non-registered
 * thread will always fail.
 */
int rseq_register_current_thread(void);

/*
 * Unregister rseq for current thread.
 */
int rseq_unregister_current_thread(void);

/*
 * Restartable sequence fallback for reading the current CPU number.
 */
int32_t rseq_fallback_current_cpu(void);

/*
 * Values returned can be either the current CPU number, -1 (rseq is
 * uninitialized), or -2 (rseq initialization has failed).
 */
static inline int32_t rseq_current_cpu_raw(void)
{
	return RSEQ_ACCESS_ONCE(rseq_get_abi()->cpu_id);
}

/*
 * Returns a possible CPU number, which is typically the current CPU.
 * The returned CPU number can be used to prepare for an rseq critical
 * section, which will confirm whether the cpu number is indeed the
 * current one, and whether rseq is initialized.
 *
 * The CPU number returned by rseq_cpu_start should always be validated
 * by passing it to a rseq asm sequence, or by comparing it to the
 * return value of rseq_current_cpu_raw() if the rseq asm sequence
 * does not need to be invoked.
 */
static inline uint32_t rseq_cpu_start(void)
{
	return RSEQ_ACCESS_ONCE(rseq_get_abi()->cpu_id_start);
}

static inline uint32_t rseq_current_cpu(void)
{
	int32_t cpu;

	cpu = rseq_current_cpu_raw();
	if (rseq_unlikely(cpu < 0))
		cpu = rseq_fallback_current_cpu();
	return cpu;
}

static inline void rseq_clear_rseq_cs(void)
{
	RSEQ_WRITE_ONCE(rseq_get_abi()->rseq_cs.arch.ptr, 0);
}

/*
 * rseq_prepare_unload() should be invoked by each thread executing a rseq
 * critical section at least once between their last critical section and
 * library unload of the library defining the rseq critical section (struct
 * rseq_cs) or the code referred to by the struct rseq_cs start_ip and
 * post_commit_offset fields. This also applies to use of rseq in code
 * generated by JIT: rseq_prepare_unload() should be invoked at least once by
 * each thread executing a rseq critical section before reclaim of the memory
 * holding the struct rseq_cs or reclaim of the code pointed to by struct
 * rseq_cs start_ip and post_commit_offset fields.
 */
static inline void rseq_prepare_unload(void)
{
	rseq_clear_rseq_cs();
}

#endif  /* RSEQ_H_ */
