/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2016-2018 Texas Instruments Incorporated - https://www.ti.com/
 * Author: Jyri Sarha <jsarha@ti.com>
 */

#ifndef __TIDSS_DISPC_REGS_H
#define __TIDSS_DISPC_REGS_H

enum dispc_common_regs {
	NOT_APPLICABLE_OFF = 0,
	DSS_REVISION_OFF,
	DSS_SYSCONFIG_OFF,
	DSS_SYSSTATUS_OFF,
	DISPC_IRQ_EOI_OFF,
	DISPC_IRQSTATUS_RAW_OFF,
	DISPC_IRQSTATUS_OFF,
	DISPC_IRQENABLE_SET_OFF,
	DISPC_IRQENABLE_CLR_OFF,
	DISPC_VID_IRQENABLE_OFF,
	DISPC_VID_IRQSTATUS_OFF,
	DISPC_VP_IRQENABLE_OFF,
	DISPC_VP_IRQSTATUS_OFF,
	WB_IRQENABLE_OFF,
	WB_IRQSTATUS_OFF,
	DISPC_GLOBAL_MFLAG_ATTRIBUTE_OFF,
	DISPC_GLOBAL_OUTPUT_ENABLE_OFF,
	DISPC_GLOBAL_BUFFER_OFF,
	DSS_CBA_CFG_OFF,
	DISPC_DBG_CONTROL_OFF,
	DISPC_DBG_STATUS_OFF,
	DISPC_CLKGATING_DISABLE_OFF,
	DISPC_SECURE_DISABLE_OFF,
	FBDC_REVISION_1_OFF,
	FBDC_REVISION_2_OFF,
	FBDC_REVISION_3_OFF,
	FBDC_REVISION_4_OFF,
	FBDC_REVISION_5_OFF,
	FBDC_REVISION_6_OFF,
	FBDC_COMMON_CONTROL_OFF,
	FBDC_CONSTANT_COLOR_0_OFF,
	FBDC_CONSTANT_COLOR_1_OFF,
	DISPC_CONNECTIONS_OFF,
	DISPC_MSS_VP1_OFF,
	DISPC_MSS_VP3_OFF,
	DISPC_COMMON_REG_TABLE_LEN,
};

/*
 * dispc_common_regmap should be defined as const u16 * and pointing
 * to a valid dss common register map for the platform, before the
 * macros bellow can be used.
 */

#define REG(r) (dispc_common_regmap[r ## _OFF])

#define DSS_REVISION			REG(DSS_REVISION)
#define DSS_SYSCONFIG			REG(DSS_SYSCONFIG)
#define DSS_SYSSTATUS			REG(DSS_SYSSTATUS)
#define DISPC_IRQ_EOI			REG(DISPC_IRQ_EOI)
#define DISPC_IRQSTATUS_RAW		REG(DISPC_IRQSTATUS_RAW)
#define DISPC_IRQSTATUS			REG(DISPC_IRQSTATUS)
#define DISPC_IRQENABLE_SET		REG(DISPC_IRQENABLE_SET)
#define DISPC_IRQENABLE_CLR		REG(DISPC_IRQENABLE_CLR)
#define DISPC_VID_IRQENABLE(n)		(REG(DISPC_VID_IRQENABLE) + (n) * 4)
#define DISPC_VID_IRQSTATUS(n)		(REG(DISPC_VID_IRQSTATUS) + (n) * 4)
#define DISPC_VP_IRQENABLE(n)		(REG(DISPC_VP_IRQENABLE) + (n) * 4)
#define DISPC_VP_IRQSTATUS(n)		(REG(DISPC_VP_IRQSTATUS) + (n) * 4)
#define WB_IRQENABLE			REG(WB_IRQENABLE)
#define WB_IRQSTATUS			REG(WB_IRQSTATUS)

#define DISPC_GLOBAL_MFLAG_ATTRIBUTE	REG(DISPC_GLOBAL_MFLAG_ATTRIBUTE)
#define DISPC_GLOBAL_OUTPUT_ENABLE	REG(DISPC_GLOBAL_OUTPUT_ENABLE)
#define DISPC_GLOBAL_BUFFER		REG(DISPC_GLOBAL_BUFFER)
#define DSS_CBA_CFG			REG(DSS_CBA_CFG)
#define DISPC_DBG_CONTROL		REG(DISPC_DBG_CONTROL)
#define DISPC_DBG_STATUS		REG(DISPC_DBG_STATUS)
#define DISPC_CLKGATING_DISABLE		REG(DISPC_CLKGATING_DISABLE)
#define DISPC_SECURE_DISABLE		REG(DISPC_SECURE_DISABLE)

#define FBDC_REVISION_1			REG(FBDC_REVISION_1)
#define FBDC_REVISION_2			REG(FBDC_REVISION_2)
#define FBDC_REVISION_3			REG(FBDC_REVISION_3)
#define FBDC_REVISION_4			REG(FBDC_REVISION_4)
#define FBDC_REVISION_5			REG(FBDC_REVISION_5)
#define FBDC_REVISION_6			REG(FBDC_REVISION_6)
#define FBDC_COMMON_CONTROL		REG(FBDC_COMMON_CONTROL)
#define FBDC_CONSTANT_COLOR_0		REG(FBDC_CONSTANT_COLOR_0)
#define FBDC_CONSTANT_COLOR_1		REG(FBDC_CONSTANT_COLOR_1)
#define DISPC_CONNECTIONS		REG(DISPC_CONNECTIONS)
#define DISPC_MSS_VP1			REG(DISPC_MSS_VP1)
#define DISPC_MSS_VP3			REG(DISPC_MSS_VP3)

/* VID */

#define DISPC_VID_ACCUH_0		0x0
#define DISPC_VID_ACCUH_1		0x4
#define DISPC_VID_ACCUH2_0		0x8
#define DISPC_VID_ACCUH2_1		0xc
#define DISPC_VID_ACCUV_0		0x10
#define DISPC_VID_ACCUV_1		0x14
#define DISPC_VID_ACCUV2_0		0x18
#define DISPC_VID_ACCUV2_1		0x1c
#define DISPC_VID_ATTRIBUTES		0x20
#define DISPC_VID_ATTRIBUTES2		0x24
#define DISPC_VID_BA_0			0x28
#define DISPC_VID_BA_1			0x2c
#define DISPC_VID_BA_UV_0		0x30
#define DISPC_VID_BA_UV_1		0x34
#define DISPC_VID_BUF_SIZE_STATUS	0x38
#define DISPC_VID_BUF_THRESHOLD		0x3c
#define DISPC_VID_CSC_COEF(n)		(0x40 + (n) * 4)

#define DISPC_VID_FIRH			0x5c
#define DISPC_VID_FIRH2			0x60
#define DISPC_VID_FIRV			0x64
#define DISPC_VID_FIRV2			0x68

#define DISPC_VID_FIR_COEFS_H0		0x6c
#define DISPC_VID_FIR_COEF_H0(phase)	(0x6c + (phase) * 4)
#define DISPC_VID_FIR_COEFS_H0_C	0x90
#define DISPC_VID_FIR_COEF_H0_C(phase)	(0x90 + (phase) * 4)

#define DISPC_VID_FIR_COEFS_H12		0xb4
#define DISPC_VID_FIR_COEF_H12(phase)	(0xb4 + (phase) * 4)
#define DISPC_VID_FIR_COEFS_H12_C	0xf4
#define DISPC_VID_FIR_COEF_H12_C(phase)	(0xf4 + (phase) * 4)

#define DISPC_VID_FIR_COEFS_V0		0x134
#define DISPC_VID_FIR_COEF_V0(phase)	(0x134 + (phase) * 4)
#define DISPC_VID_FIR_COEFS_V0_C	0x158
#define DISPC_VID_FIR_COEF_V0_C(phase)	(0x158 + (phase) * 4)

#define DISPC_VID_FIR_COEFS_V12		0x17c
#define DISPC_VID_FIR_COEF_V12(phase)	(0x17c + (phase) * 4)
#define DISPC_VID_FIR_COEFS_V12_C	0x1bc
#define DISPC_VID_FIR_COEF_V12_C(phase)	(0x1bc + (phase) * 4)

#define DISPC_VID_GLOBAL_ALPHA		0x1fc
#define DISPC_VID_K2G_IRQENABLE		0x200 /* K2G */
#define DISPC_VID_K2G_IRQSTATUS		0x204 /* K2G */
#define DISPC_VID_MFLAG_THRESHOLD	0x208
#define DISPC_VID_PICTURE_SIZE		0x20c
#define DISPC_VID_PIXEL_INC		0x210
#define DISPC_VID_K2G_POSITION		0x214 /* K2G */
#define DISPC_VID_PRELOAD		0x218
#define DISPC_VID_ROW_INC		0x21c
#define DISPC_VID_SIZE			0x220
#define DISPC_VID_BA_EXT_0		0x22c
#define DISPC_VID_BA_EXT_1		0x230
#define DISPC_VID_BA_UV_EXT_0		0x234
#define DISPC_VID_BA_UV_EXT_1		0x238
#define DISPC_VID_CSC_COEF7		0x23c
#define DISPC_VID_ROW_INC_UV		0x248
#define DISPC_VID_CLUT			0x260
#define DISPC_VID_SAFETY_ATTRIBUTES	0x2a0
#define DISPC_VID_SAFETY_CAPT_SIGNATURE	0x2a4
#define DISPC_VID_SAFETY_POSITION	0x2a8
#define DISPC_VID_SAFETY_REF_SIGNATURE	0x2ac
#define DISPC_VID_SAFETY_SIZE		0x2b0
#define DISPC_VID_SAFETY_LFSR_SEED	0x2b4
#define DISPC_VID_LUMAKEY		0x2b8
#define DISPC_VID_DMA_BUFSIZE		0x2bc /* J721E */

/* OVR */

#define DISPC_OVR_CONFIG		0x0
#define DISPC_OVR_VIRTVP		0x4 /* J721E */
#define DISPC_OVR_DEFAULT_COLOR		0x8
#define DISPC_OVR_DEFAULT_COLOR2	0xc
#define DISPC_OVR_TRANS_COLOR_MAX	0x10
#define DISPC_OVR_TRANS_COLOR_MAX2	0x14
#define DISPC_OVR_TRANS_COLOR_MIN	0x18
#define DISPC_OVR_TRANS_COLOR_MIN2	0x1c
#define DISPC_OVR_ATTRIBUTES(n)		(0x20 + (n) * 4)
#define DISPC_OVR_ATTRIBUTES2(n)	(0x34 + (n) * 4) /* J721E */
/* VP */

#define DISPC_VP_CONFIG				0x0
#define DISPC_VP_CONTROL			0x4
#define DISPC_VP_CSC_COEF0			0x8
#define DISPC_VP_CSC_COEF1			0xc
#define DISPC_VP_CSC_COEF2			0x10
#define DISPC_VP_DATA_CYCLE_0			0x14
#define DISPC_VP_DATA_CYCLE_1			0x18
#define DISPC_VP_K2G_GAMMA_TABLE		0x20 /* K2G */
#define DISPC_VP_K2G_IRQENABLE			0x3c /* K2G */
#define DISPC_VP_K2G_IRQSTATUS			0x40 /* K2G */
#define DISPC_VP_DATA_CYCLE_2			0x1c
#define DISPC_VP_LINE_NUMBER			0x44
#define DISPC_VP_POL_FREQ			0x4c
#define DISPC_VP_SIZE_SCREEN			0x50
#define DISPC_VP_TIMING_H			0x54
#define DISPC_VP_TIMING_V			0x58
#define DISPC_VP_CSC_COEF3			0x5c
#define DISPC_VP_CSC_COEF4			0x60
#define DISPC_VP_CSC_COEF5			0x64
#define DISPC_VP_CSC_COEF6			0x68
#define DISPC_VP_CSC_COEF7			0x6c
#define DISPC_VP_SAFETY_ATTRIBUTES_0		0x70
#define DISPC_VP_SAFETY_ATTRIBUTES_1		0x74
#define DISPC_VP_SAFETY_ATTRIBUTES_2		0x78
#define DISPC_VP_SAFETY_ATTRIBUTES_3		0x7c
#define DISPC_VP_SAFETY_CAPT_SIGNATURE_0	0x90
#define DISPC_VP_SAFETY_CAPT_SIGNATURE_1	0x94
#define DISPC_VP_SAFETY_CAPT_SIGNATURE_2	0x98
#define DISPC_VP_SAFETY_CAPT_SIGNATURE_3	0x9c
#define DISPC_VP_SAFETY_POSITION_0		0xb0
#define DISPC_VP_SAFETY_POSITION_1		0xb4
#define DISPC_VP_SAFETY_POSITION_2		0xb8
#define DISPC_VP_SAFETY_POSITION_3		0xbc
#define DISPC_VP_SAFETY_REF_SIGNATURE_0		0xd0
#define DISPC_VP_SAFETY_REF_SIGNATURE_1		0xd4
#define DISPC_VP_SAFETY_REF_SIGNATURE_2		0xd8
#define DISPC_VP_SAFETY_REF_SIGNATURE_3		0xdc
#define DISPC_VP_SAFETY_SIZE_0			0xf0
#define DISPC_VP_SAFETY_SIZE_1			0xf4
#define DISPC_VP_SAFETY_SIZE_2			0xf8
#define DISPC_VP_SAFETY_SIZE_3			0xfc
#define DISPC_VP_SAFETY_LFSR_SEED		0x110
#define DISPC_VP_GAMMA_TABLE			0x120
#define DISPC_VP_DSS_OLDI_CFG			0x160
#define DISPC_VP_DSS_OLDI_STATUS		0x164
#define DISPC_VP_DSS_OLDI_LB			0x168
#define DISPC_VP_DSS_MERGE_SPLIT		0x16c /* J721E */
#define DISPC_VP_DSS_DMA_THREADSIZE		0x170 /* J721E */
#define DISPC_VP_DSS_DMA_THREADSIZE_STATUS	0x174 /* J721E */

/*
 * OLDI IO_CTRL register offsets. On AM654 the registers are found
 * from CTRL_MMR0, there the syscon regmap should map 0x14 bytes from
 * CTRLMMR0P1_OLDI_DAT0_IO_CTRL to CTRLMMR0P1_OLDI_CLK_IO_CTRL
 * register range.
 */
#define OLDI_DAT0_IO_CTRL			0x00
#define OLDI_DAT1_IO_CTRL			0x04
#define OLDI_DAT2_IO_CTRL			0x08
#define OLDI_DAT3_IO_CTRL			0x0C
#define OLDI_CLK_IO_CTRL			0x10

#define OLDI_PWRDN_TX				BIT(8)

#endif /* __TIDSS_DISPC_REGS_H */
