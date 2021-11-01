{
	"valid map access into an array with a constant",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr_unpriv = "R0 leaks addr",
	.result_unpriv = REJECT,
	.result = ACCEPT,
},
{
	"valid map access into an array with a register",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_IMM(BPF_LSH, BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr_unpriv = "R0 leaks addr",
	.result_unpriv = REJECT,
	.result = ACCEPT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"valid map access into an array with a variable",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 5),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_JMP_IMM(BPF_JGE, BPF_REG_1, MAX_ENTRIES, 3),
	BPF_ALU64_IMM(BPF_LSH, BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr_unpriv = "R0 leaks addr",
	.result_unpriv = REJECT,
	.result = ACCEPT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"valid map access into an array with a signed variable",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 9),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_JMP32_IMM(BPF_JSGT, BPF_REG_1, 0xffffffff, 1),
	BPF_MOV32_IMM(BPF_REG_1, 0),
	BPF_MOV32_IMM(BPF_REG_2, MAX_ENTRIES),
	BPF_JMP_REG(BPF_JSGT, BPF_REG_2, BPF_REG_1, 1),
	BPF_MOV32_IMM(BPF_REG_1, 0),
	BPF_ALU32_IMM(BPF_LSH, BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr_unpriv = "R0 leaks addr",
	.result_unpriv = REJECT,
	.result = ACCEPT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"invalid map access into an array with a constant",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, (MAX_ENTRIES + 1) << 2,
		   offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr = "invalid access to map value, value_size=48 off=48 size=8",
	.result = REJECT,
},
{
	"invalid map access into an array with a register",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_MOV64_IMM(BPF_REG_1, MAX_ENTRIES + 1),
	BPF_ALU64_IMM(BPF_LSH, BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr = "R0 min value is outside of the allowed memory range",
	.result = REJECT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"invalid map access into an array with a variable",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_LSH, BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr = "R0 unbounded memory access, make sure to bounds check any such access",
	.result = REJECT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"invalid map access into an array with no floor check",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 7),
	BPF_LDX_MEM(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV32_IMM(BPF_REG_2, MAX_ENTRIES),
	BPF_JMP_REG(BPF_JSGT, BPF_REG_2, BPF_REG_1, 1),
	BPF_MOV32_IMM(BPF_REG_1, 0),
	BPF_ALU32_IMM(BPF_LSH, BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr_unpriv = "R0 leaks addr",
	.errstr = "R0 unbounded memory access",
	.result_unpriv = REJECT,
	.result = REJECT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"invalid map access into an array with a invalid max check",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 7),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV32_IMM(BPF_REG_2, MAX_ENTRIES + 1),
	BPF_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_1, 1),
	BPF_MOV32_IMM(BPF_REG_1, 0),
	BPF_ALU32_IMM(BPF_LSH, BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3 },
	.errstr_unpriv = "R0 leaks addr",
	.errstr = "invalid access to map value, value_size=48 off=44 size=8",
	.result_unpriv = REJECT,
	.result = REJECT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"invalid map access into an array with a invalid max check",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 10),
	BPF_MOV64_REG(BPF_REG_8, BPF_REG_0),
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_8),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_0,
		    offsetof(struct test_val, foo)),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 3, 11 },
	.errstr = "R0 pointer += pointer",
	.result = REJECT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"valid read map access into a read-only array 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 1),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_ro = { 3 },
	.result = ACCEPT,
	.retval = 28,
},
{
	"valid read map access into a read-only array 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 6),

	BPF_MOV64_REG(BPF_REG_1, BPF_REG_0),
	BPF_MOV64_IMM(BPF_REG_2, 4),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_MOV64_IMM(BPF_REG_4, 0),
	BPF_MOV64_IMM(BPF_REG_5, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
		     BPF_FUNC_csum_diff),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_0, 0xffff),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.fixup_map_array_ro = { 3 },
	.result = ACCEPT,
	.retval = 65507,
},
{
	"invalid write map access into a read-only array 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, 42),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_ro = { 3 },
	.result = REJECT,
	.errstr = "write into map forbidden",
},
{
	"invalid write map access into a read-only array 2",
	.insns = {
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 5),
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_6),
	BPF_MOV64_IMM(BPF_REG_2, 0),
	BPF_MOV64_REG(BPF_REG_3, BPF_REG_0),
	BPF_MOV64_IMM(BPF_REG_4, 8),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
		     BPF_FUNC_skb_load_bytes),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.fixup_map_array_ro = { 4 },
	.result = REJECT,
	.errstr = "write into map forbidden",
},
{
	"valid write map access into a write-only array 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 1),
	BPF_ST_MEM(BPF_DW, BPF_REG_0, 0, 42),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_wo = { 3 },
	.result = ACCEPT,
	.retval = 1,
},
{
	"valid write map access into a write-only array 2",
	.insns = {
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_1),
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 5),
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_6),
	BPF_MOV64_IMM(BPF_REG_2, 0),
	BPF_MOV64_REG(BPF_REG_3, BPF_REG_0),
	BPF_MOV64_IMM(BPF_REG_4, 8),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
		     BPF_FUNC_skb_load_bytes),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.fixup_map_array_wo = { 4 },
	.result = ACCEPT,
	.retval = 0,
},
{
	"invalid read map access into a write-only array 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 1),
	BPF_LDX_MEM(BPF_DW, BPF_REG_0, BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_wo = { 3 },
	.result = REJECT,
	.errstr = "read from map forbidden",
},
{
	"invalid read map access into a write-only array 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 6),

	BPF_MOV64_REG(BPF_REG_1, BPF_REG_0),
	BPF_MOV64_IMM(BPF_REG_2, 4),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_MOV64_IMM(BPF_REG_4, 0),
	BPF_MOV64_IMM(BPF_REG_5, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
		     BPF_FUNC_csum_diff),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.fixup_map_array_wo = { 3 },
	.result = REJECT,
	.errstr = "read from map forbidden",
},
