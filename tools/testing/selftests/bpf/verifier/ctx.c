{
	"context stores via ST",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_ST_MEM(BPF_DW, BPF_REG_1, offsetof(struct __sk_buff, mark), 0),
	BPF_EXIT_INSN(),
	},
	.errstr = "BPF_ST stores into R1 ctx is not allowed",
	.result = REJECT,
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
},
{
	"context stores via XADD",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_RAW_INSN(BPF_STX | BPF_XADD | BPF_W, BPF_REG_1,
		     BPF_REG_0, offsetof(struct __sk_buff, mark), 0),
	BPF_EXIT_INSN(),
	},
	.errstr = "BPF_XADD stores into R1 ctx is not allowed",
	.result = REJECT,
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
},
{
	"arithmetic ops make PTR_TO_CTX unusable",
	.insns = {
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1,
			      offsetof(struct __sk_buff, data) -
			      offsetof(struct __sk_buff, mark)),
		BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1,
			    offsetof(struct __sk_buff, mark)),
		BPF_EXIT_INSN(),
	},
	.errstr = "dereference of modified ctx ptr",
	.result = REJECT,
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
},
{
	"pass unmodified ctx pointer to helper",
	.insns = {
		BPF_MOV64_IMM(BPF_REG_2, 0),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_csum_update),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.result = ACCEPT,
},
{
	"pass modified ctx pointer to helper, 1",
	.insns = {
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -612),
		BPF_MOV64_IMM(BPF_REG_2, 0),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_csum_update),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.result = REJECT,
	.errstr = "dereference of modified ctx ptr",
},
{
	"pass modified ctx pointer to helper, 2",
	.insns = {
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -612),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_socket_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.result_unpriv = REJECT,
	.result = REJECT,
	.errstr_unpriv = "dereference of modified ctx ptr",
	.errstr = "dereference of modified ctx ptr",
},
{
	"pass modified ctx pointer to helper, 3",
	.insns = {
		BPF_LDX_MEM(BPF_W, BPF_REG_3, BPF_REG_1, 0),
		BPF_ALU64_IMM(BPF_AND, BPF_REG_3, 4),
		BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_3),
		BPF_MOV64_IMM(BPF_REG_2, 0),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_csum_update),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.result = REJECT,
	.errstr = "variable ctx access var_off=(0x0; 0x4)",
},
{
	"pass ctx or null check, 1: ctx",
	.insns = {
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_netns_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
	.expected_attach_type = BPF_CGROUP_UDP6_SENDMSG,
	.result = ACCEPT,
},
{
	"pass ctx or null check, 2: null",
	.insns = {
		BPF_MOV64_IMM(BPF_REG_1, 0),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_netns_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
	.expected_attach_type = BPF_CGROUP_UDP6_SENDMSG,
	.result = ACCEPT,
},
{
	"pass ctx or null check, 3: 1",
	.insns = {
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_netns_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
	.expected_attach_type = BPF_CGROUP_UDP6_SENDMSG,
	.result = REJECT,
	.errstr = "R1 type=inv expected=ctx",
},
{
	"pass ctx or null check, 4: ctx - const",
	.insns = {
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -612),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_netns_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
	.expected_attach_type = BPF_CGROUP_UDP6_SENDMSG,
	.result = REJECT,
	.errstr = "dereference of modified ctx ptr",
},
{
	"pass ctx or null check, 5: null (connect)",
	.insns = {
		BPF_MOV64_IMM(BPF_REG_1, 0),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_netns_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
	.expected_attach_type = BPF_CGROUP_INET4_CONNECT,
	.result = ACCEPT,
},
{
	"pass ctx or null check, 6: null (bind)",
	.insns = {
		BPF_MOV64_IMM(BPF_REG_1, 0),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_netns_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK,
	.expected_attach_type = BPF_CGROUP_INET4_POST_BIND,
	.result = ACCEPT,
},
{
	"pass ctx or null check, 7: ctx (bind)",
	.insns = {
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_socket_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK,
	.expected_attach_type = BPF_CGROUP_INET4_POST_BIND,
	.result = ACCEPT,
},
{
	"pass ctx or null check, 8: null (bind)",
	.insns = {
		BPF_MOV64_IMM(BPF_REG_1, 0),
		BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
			     BPF_FUNC_get_socket_cookie),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_CGROUP_SOCK,
	.expected_attach_type = BPF_CGROUP_INET4_POST_BIND,
	.result = REJECT,
	.errstr = "R1 type=inv expected=ctx",
},
