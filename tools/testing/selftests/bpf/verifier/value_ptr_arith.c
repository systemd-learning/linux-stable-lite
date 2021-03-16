{
	"map access: known scalar += value_ptr from different maps",
	.insns = {
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1,
		    offsetof(struct __sk_buff, len)),
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 1, 3),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 1, 2),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_16b = { 5 },
	.fixup_map_array_48b = { 8 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R1 tried to add from different maps",
	.retval = 1,
},
{
	"map access: value_ptr -= known scalar from different maps",
	.insns = {
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1,
		    offsetof(struct __sk_buff, len)),
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 1, 3),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 1, 2),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_16b = { 5 },
	.fixup_map_array_48b = { 8 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 min value is outside of the allowed memory range",
	.retval = 1,
},
{
	"map access: known scalar += value_ptr from different maps, but same value properties",
	.insns = {
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1,
		    offsetof(struct __sk_buff, len)),
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 1, 3),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 1, 2),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_hash_48b = { 5 },
	.fixup_map_array_48b = { 8 },
	.result = ACCEPT,
	.retval = 1,
},
{
	"map access: mixing value pointer and scalar, 1",
	.insns = {
	// load map value pointer into r0 and r2
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_LD_MAP_FD(BPF_REG_ARG1, 0),
	BPF_MOV64_REG(BPF_REG_ARG2, BPF_REG_FP),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_ARG2, -16),
	BPF_ST_MEM(BPF_DW, BPF_REG_FP, -16, 0),
	BPF_EMIT_CALL(BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 0, 1),
	BPF_EXIT_INSN(),
	// load some number from the map into r1
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	// depending on r1, branch:
	BPF_JMP_IMM(BPF_JNE, BPF_REG_1, 0, 3),
	// branch A
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_0),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	BPF_JMP_A(2),
	// branch B
	BPF_MOV64_IMM(BPF_REG_2, 0),
	BPF_MOV64_IMM(BPF_REG_3, 0x100000),
	// common instruction
	BPF_ALU64_REG(BPF_ADD, BPF_REG_2, BPF_REG_3),
	// depending on r1, branch:
	BPF_JMP_IMM(BPF_JNE, BPF_REG_1, 0, 1),
	// branch A
	BPF_JMP_A(4),
	// branch B
	BPF_MOV64_IMM(BPF_REG_0, 0x13371337),
	// verifier follows fall-through
	BPF_JMP_IMM(BPF_JNE, BPF_REG_2, 0x100000, 2),
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	// fake-dead code; targeted from branch A to
	// prevent dead code sanitization
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 1 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R2 tried to add from different pointers or scalars",
	.retval = 0,
},
{
	"map access: mixing value pointer and scalar, 2",
	.insns = {
	// load map value pointer into r0 and r2
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_LD_MAP_FD(BPF_REG_ARG1, 0),
	BPF_MOV64_REG(BPF_REG_ARG2, BPF_REG_FP),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_ARG2, -16),
	BPF_ST_MEM(BPF_DW, BPF_REG_FP, -16, 0),
	BPF_EMIT_CALL(BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 0, 1),
	BPF_EXIT_INSN(),
	// load some number from the map into r1
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	// depending on r1, branch:
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 3),
	// branch A
	BPF_MOV64_IMM(BPF_REG_2, 0),
	BPF_MOV64_IMM(BPF_REG_3, 0x100000),
	BPF_JMP_A(2),
	// branch B
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_0),
	BPF_MOV64_IMM(BPF_REG_3, 0),
	// common instruction
	BPF_ALU64_REG(BPF_ADD, BPF_REG_2, BPF_REG_3),
	// depending on r1, branch:
	BPF_JMP_IMM(BPF_JNE, BPF_REG_1, 0, 1),
	// branch A
	BPF_JMP_A(4),
	// branch B
	BPF_MOV64_IMM(BPF_REG_0, 0x13371337),
	// verifier follows fall-through
	BPF_JMP_IMM(BPF_JNE, BPF_REG_2, 0x100000, 2),
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	// fake-dead code; targeted from branch A to
	// prevent dead code sanitization
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 1 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R2 tried to add from different maps, paths, or prohibited types",
	.retval = 0,
},
{
	"sanitation: alu with different scalars 1",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_LD_MAP_FD(BPF_REG_ARG1, 0),
	BPF_MOV64_REG(BPF_REG_ARG2, BPF_REG_FP),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_ARG2, -16),
	BPF_ST_MEM(BPF_DW, BPF_REG_FP, -16, 0),
	BPF_EMIT_CALL(BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 0, 1),
	BPF_EXIT_INSN(),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, 3),
	BPF_MOV64_IMM(BPF_REG_2, 0),
	BPF_MOV64_IMM(BPF_REG_3, 0x100000),
	BPF_JMP_A(2),
	BPF_MOV64_IMM(BPF_REG_2, 42),
	BPF_MOV64_IMM(BPF_REG_3, 0x100001),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_2, BPF_REG_3),
	BPF_MOV64_REG(BPF_REG_0, BPF_REG_2),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 1 },
	.result = ACCEPT,
	.retval = 0x100000,
},
{
	"sanitation: alu with different scalars 2",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_1),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_FP),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -16),
	BPF_ST_MEM(BPF_DW, BPF_REG_FP, -16, 0),
	BPF_EMIT_CALL(BPF_FUNC_map_delete_elem),
	BPF_MOV64_REG(BPF_REG_7, BPF_REG_0),
	BPF_MOV64_REG(BPF_REG_1, BPF_REG_6),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_FP),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -16),
	BPF_EMIT_CALL(BPF_FUNC_map_delete_elem),
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_0),
	BPF_MOV64_REG(BPF_REG_8, BPF_REG_6),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_8, BPF_REG_7),
	BPF_MOV64_REG(BPF_REG_0, BPF_REG_8),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 1 },
	.result = ACCEPT,
	.retval = -EINVAL * 2,
},
{
	"sanitation: alu with different scalars 3",
	.insns = {
	BPF_MOV64_IMM(BPF_REG_0, EINVAL),
	BPF_ALU64_IMM(BPF_MUL, BPF_REG_0, -1),
	BPF_MOV64_REG(BPF_REG_7, BPF_REG_0),
	BPF_MOV64_IMM(BPF_REG_0, EINVAL),
	BPF_ALU64_IMM(BPF_MUL, BPF_REG_0, -1),
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_0),
	BPF_MOV64_REG(BPF_REG_8, BPF_REG_6),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_8, BPF_REG_7),
	BPF_MOV64_REG(BPF_REG_0, BPF_REG_8),
	BPF_EXIT_INSN(),
	},
	.result = ACCEPT,
	.retval = -EINVAL * 2,
},
{
	"map access: value_ptr += known scalar, upper oob arith, test 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_MOV64_IMM(BPF_REG_1, 48),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: value_ptr += known scalar, upper oob arith, test 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_MOV64_IMM(BPF_REG_1, 49),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: value_ptr += known scalar, upper oob arith, test 3",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_MOV64_IMM(BPF_REG_1, 47),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: value_ptr -= known scalar, lower oob arith, test 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 5),
	BPF_MOV64_IMM(BPF_REG_1, 47),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, 48),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R0 min value is outside of the allowed memory range",
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
},
{
	"map access: value_ptr -= known scalar, lower oob arith, test 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 7),
	BPF_MOV64_IMM(BPF_REG_1, 47),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, 48),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, 1),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: value_ptr -= known scalar, lower oob arith, test 3",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 5),
	BPF_MOV64_IMM(BPF_REG_1, 47),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, 47),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: known scalar += value_ptr",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 1,
},
{
	"map access: value_ptr += known scalar, 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 1,
},
{
	"map access: value_ptr += known scalar, 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, 49),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "invalid access to map value",
},
{
	"map access: value_ptr += known scalar, 3",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, -1),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "invalid access to map value",
},
{
	"map access: value_ptr += known scalar, 4",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 7),
	BPF_MOV64_IMM(BPF_REG_1, 5),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, -2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, -1),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: value_ptr += known scalar, 5",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, (6 + 1) * sizeof(int)),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 0xabcdef12,
},
{
	"map access: value_ptr += known scalar, 6",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 5),
	BPF_MOV64_IMM(BPF_REG_1, (3 + 1) * sizeof(int)),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, 3 * sizeof(int)),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 0xabcdef12,
},
{
	"map access: value_ptr += N, value_ptr -= N known scalar",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 6),
	BPF_MOV32_IMM(BPF_REG_1, 0x12345678),
	BPF_STX_MEM(BPF_W, BPF_REG_0, BPF_REG_1, 0),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 2),
	BPF_MOV64_IMM(BPF_REG_1, 2),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 0x12345678,
},
{
	"map access: unknown scalar += value_ptr, 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0xf),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 1,
},
{
	"map access: unknown scalar += value_ptr, 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 31),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 0xabcdef12,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"map access: unknown scalar += value_ptr, 3",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 8),
	BPF_MOV64_IMM(BPF_REG_1, -1),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_MOV64_IMM(BPF_REG_1, 1),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 31),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 0xabcdef12,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"map access: unknown scalar += value_ptr, 4",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 6),
	BPF_MOV64_IMM(BPF_REG_1, 19),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 31),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R1 max value is outside of the allowed memory range",
	.errstr_unpriv = "R1 pointer arithmetic of map value goes out of range",
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"map access: value_ptr += unknown scalar, 1",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0xf),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 1,
},
{
	"map access: value_ptr += unknown scalar, 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 31),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 0xabcdef12,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"map access: value_ptr += unknown scalar, 3",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 11),
	BPF_LDX_MEM(BPF_DW, BPF_REG_1, BPF_REG_0, 0),
	BPF_LDX_MEM(BPF_DW, BPF_REG_2, BPF_REG_0, 8),
	BPF_LDX_MEM(BPF_DW, BPF_REG_3, BPF_REG_0, 16),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0xf),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_3, 1),
	BPF_ALU64_IMM(BPF_OR, BPF_REG_3, 1),
	BPF_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_3, 4),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_3),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	BPF_MOV64_IMM(BPF_REG_0, 2),
	BPF_JMP_IMM(BPF_JA, 0, 0, -3),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.retval = 1,
},
{
	"map access: value_ptr += value_ptr",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 2),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R0 pointer += pointer prohibited",
},
{
	"map access: known scalar -= value_ptr",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R1 tried to subtract pointer from scalar",
},
{
	"map access: value_ptr -= known scalar",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3),
	BPF_MOV64_IMM(BPF_REG_1, 4),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R0 min value is outside of the allowed memory range",
},
{
	"map access: value_ptr -= known scalar, 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 5),
	BPF_MOV64_IMM(BPF_REG_1, 6),
	BPF_MOV64_IMM(BPF_REG_2, 4),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_2),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: unknown scalar -= value_ptr",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0xf),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_1, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R1 tried to subtract pointer from scalar",
},
{
	"map access: value_ptr -= unknown scalar",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 4),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0xf),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R0 min value is negative",
},
{
	"map access: value_ptr -= unknown scalar, 2",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 8),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0xf),
	BPF_ALU64_IMM(BPF_OR, BPF_REG_1, 0x7),
	BPF_ALU64_REG(BPF_ADD, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_ALU64_IMM(BPF_AND, BPF_REG_1, 0x7),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_1),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = ACCEPT,
	.result_unpriv = REJECT,
	.errstr_unpriv = "R0 pointer arithmetic of map value goes out of range",
	.retval = 1,
},
{
	"map access: value_ptr -= value_ptr",
	.insns = {
	BPF_ST_MEM(BPF_DW, BPF_REG_10, -8, 0),
	BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -8),
	BPF_LD_MAP_FD(BPF_REG_1, 0),
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
	BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 2),
	BPF_ALU64_REG(BPF_SUB, BPF_REG_0, BPF_REG_0),
	BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_0, 0),
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
	},
	.fixup_map_array_48b = { 3 },
	.result = REJECT,
	.errstr = "R0 invalid mem access 'inv'",
	.errstr_unpriv = "R0 pointer -= pointer prohibited",
},
{
	"32bit pkt_ptr -= scalar",
	.insns = {
	BPF_LDX_MEM(BPF_W, BPF_REG_8, BPF_REG_1,
		    offsetof(struct __sk_buff, data_end)),
	BPF_LDX_MEM(BPF_W, BPF_REG_7, BPF_REG_1,
		    offsetof(struct __sk_buff, data)),
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_7),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_6, 40),
	BPF_JMP_REG(BPF_JGT, BPF_REG_6, BPF_REG_8, 2),
	BPF_ALU32_REG(BPF_MOV, BPF_REG_4, BPF_REG_7),
	BPF_ALU32_REG(BPF_SUB, BPF_REG_6, BPF_REG_4),
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.result = ACCEPT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
{
	"32bit scalar -= pkt_ptr",
	.insns = {
	BPF_LDX_MEM(BPF_W, BPF_REG_8, BPF_REG_1,
		    offsetof(struct __sk_buff, data_end)),
	BPF_LDX_MEM(BPF_W, BPF_REG_7, BPF_REG_1,
		    offsetof(struct __sk_buff, data)),
	BPF_MOV64_REG(BPF_REG_6, BPF_REG_7),
	BPF_ALU64_IMM(BPF_ADD, BPF_REG_6, 40),
	BPF_JMP_REG(BPF_JGT, BPF_REG_6, BPF_REG_8, 2),
	BPF_ALU32_REG(BPF_MOV, BPF_REG_4, BPF_REG_6),
	BPF_ALU32_REG(BPF_SUB, BPF_REG_4, BPF_REG_7),
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
	},
	.prog_type = BPF_PROG_TYPE_SCHED_CLS,
	.result = ACCEPT,
	.flags = F_NEEDS_EFFICIENT_UNALIGNED_ACCESS,
},
