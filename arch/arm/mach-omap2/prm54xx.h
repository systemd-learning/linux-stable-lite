/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * OMAP54xx PRM instance offset macros
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - https://www.ti.com
 *
 * Paul Walmsley (paul@pwsan.com)
 * Rajendra Nayak (rnayak@ti.com)
 * Benoit Cousson (b-cousson@ti.com)
 *
 * This file is automatically generated from the OMAP hardware databases.
 * We respectfully ask that any modifications to this file be coordinated
 * with the public linux-omap@vger.kernel.org mailing list and the
 * authors above to ensure that the autogeneration scripts are kept
 * up-to-date with the file contents.
 */

#ifndef __ARCH_ARM_MACH_OMAP2_PRM54XX_H
#define __ARCH_ARM_MACH_OMAP2_PRM54XX_H

#include "prm44xx_54xx.h"
#include "prm.h"

#define OMAP54XX_PRM_BASE		0x4ae06000

#define OMAP54XX_PRM_REGADDR(inst, reg)				\
	OMAP2_L4_IO_ADDRESS(OMAP54XX_PRM_BASE + (inst) + (reg))


/* PRM instances */
#define OMAP54XX_PRM_OCP_SOCKET_INST	0x0000
#define OMAP54XX_PRM_CKGEN_INST		0x0100
#define OMAP54XX_PRM_MPU_INST		0x0300
#define OMAP54XX_PRM_DSP_INST		0x0400
#define OMAP54XX_PRM_ABE_INST		0x0500
#define OMAP54XX_PRM_COREAON_INST	0x0600
#define OMAP54XX_PRM_CORE_INST		0x0700
#define OMAP54XX_PRM_IVA_INST		0x1200
#define OMAP54XX_PRM_CAM_INST		0x1300
#define OMAP54XX_PRM_DSS_INST		0x1400
#define OMAP54XX_PRM_GPU_INST		0x1500
#define OMAP54XX_PRM_L3INIT_INST	0x1600
#define OMAP54XX_PRM_CUSTEFUSE_INST	0x1700
#define OMAP54XX_PRM_WKUPAON_INST	0x1800
#define OMAP54XX_PRM_WKUPAON_CM_INST	0x1900
#define OMAP54XX_PRM_EMU_INST		0x1a00
#define OMAP54XX_PRM_EMU_CM_INST	0x1b00
#define OMAP54XX_PRM_DEVICE_INST	0x1c00
#define OMAP54XX_PRM_INSTR_INST		0x1f00

/* PRM clockdomain register offsets (from instance start) */
#define OMAP54XX_PRM_WKUPAON_CM_WKUPAON_CDOFFS	0x0000
#define OMAP54XX_PRM_EMU_CM_EMU_CDOFFS		0x0000

/* PRM */

/* PRM.OCP_SOCKET_PRM register offsets */
#define OMAP54XX_REVISION_PRM_OFFSET				0x0000
#define OMAP54XX_PRM_IRQSTATUS_MPU_OFFSET			0x0010
#define OMAP54XX_PRM_IRQSTATUS_MPU_2_OFFSET			0x0014
#define OMAP54XX_PRM_IRQENABLE_MPU_OFFSET			0x0018
#define OMAP54XX_PRM_IRQENABLE_MPU_2_OFFSET			0x001c
#define OMAP54XX_PRM_IRQSTATUS_IPU_OFFSET			0x0020
#define OMAP54XX_PRM_IRQENABLE_IPU_OFFSET			0x0028
#define OMAP54XX_PRM_IRQSTATUS_DSP_OFFSET			0x0030
#define OMAP54XX_PRM_IRQENABLE_DSP_OFFSET			0x0038
#define OMAP54XX_CM_PRM_PROFILING_CLKCTRL_OFFSET		0x0040
#define OMAP54XX_CM_PRM_PROFILING_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_OCP_SOCKET_INST, 0x0040)
#define OMAP54XX_PRM_DEBUG_OUT_OFFSET				0x0084
#define OMAP54XX_PRM_DEBUG_TRANS_CFG_OFFSET			0x0090
#define OMAP54XX_PRM_DEBUG_OFF_TRANS_OFFSET			0x0094
#define OMAP54XX_PRM_DEBUG_CORE_RET_TRANS_OFFSET		0x0098
#define OMAP54XX_PRM_DEBUG_MPU_RET_TRANS_OFFSET			0x009c
#define OMAP54XX_PRM_DEBUG_MM_RET_TRANS_OFFSET			0x00a0
#define OMAP54XX_PRM_DEBUG_WKUPAON_FD_TRANS_OFFSET		0x00a4

/* PRM.CKGEN_PRM register offsets */
#define OMAP54XX_CM_CLKSEL_ABE_DSS_SYS_OFFSET			0x0000
#define OMAP54XX_CM_CLKSEL_ABE_DSS_SYS				OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_CKGEN_INST, 0x0000)
#define OMAP54XX_CM_CLKSEL_WKUPAON_OFFSET			0x0008
#define OMAP54XX_CM_CLKSEL_WKUPAON				OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_CKGEN_INST, 0x0008)
#define OMAP54XX_CM_CLKSEL_ABE_PLL_REF_OFFSET			0x000c
#define OMAP54XX_CM_CLKSEL_ABE_PLL_REF				OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_CKGEN_INST, 0x000c)
#define OMAP54XX_CM_CLKSEL_SYS_OFFSET				0x0010
#define OMAP54XX_CM_CLKSEL_SYS					OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_CKGEN_INST, 0x0010)

/* PRM.MPU_PRM register offsets */
#define OMAP54XX_PM_MPU_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_MPU_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_MPU_MPU_CONTEXT_OFFSET			0x0024

/* PRM.DSP_PRM register offsets */
#define OMAP54XX_PM_DSP_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_DSP_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_DSP_RSTCTRL_OFFSET				0x0010
#define OMAP54XX_RM_DSP_RSTST_OFFSET				0x0014
#define OMAP54XX_RM_DSP_DSP_CONTEXT_OFFSET			0x0024

/* PRM.ABE_PRM register offsets */
#define OMAP54XX_PM_ABE_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_ABE_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_ABE_AESS_CONTEXT_OFFSET			0x002c
#define OMAP54XX_PM_ABE_MCPDM_WKDEP_OFFSET			0x0030
#define OMAP54XX_RM_ABE_MCPDM_CONTEXT_OFFSET			0x0034
#define OMAP54XX_PM_ABE_DMIC_WKDEP_OFFSET			0x0038
#define OMAP54XX_RM_ABE_DMIC_CONTEXT_OFFSET			0x003c
#define OMAP54XX_PM_ABE_MCASP_WKDEP_OFFSET			0x0040
#define OMAP54XX_RM_ABE_MCASP_CONTEXT_OFFSET			0x0044
#define OMAP54XX_PM_ABE_MCBSP1_WKDEP_OFFSET			0x0048
#define OMAP54XX_RM_ABE_MCBSP1_CONTEXT_OFFSET			0x004c
#define OMAP54XX_PM_ABE_MCBSP2_WKDEP_OFFSET			0x0050
#define OMAP54XX_RM_ABE_MCBSP2_CONTEXT_OFFSET			0x0054
#define OMAP54XX_PM_ABE_MCBSP3_WKDEP_OFFSET			0x0058
#define OMAP54XX_RM_ABE_MCBSP3_CONTEXT_OFFSET			0x005c
#define OMAP54XX_PM_ABE_SLIMBUS1_WKDEP_OFFSET			0x0060
#define OMAP54XX_RM_ABE_SLIMBUS1_CONTEXT_OFFSET			0x0064
#define OMAP54XX_PM_ABE_TIMER5_WKDEP_OFFSET			0x0068
#define OMAP54XX_RM_ABE_TIMER5_CONTEXT_OFFSET			0x006c
#define OMAP54XX_PM_ABE_TIMER6_WKDEP_OFFSET			0x0070
#define OMAP54XX_RM_ABE_TIMER6_CONTEXT_OFFSET			0x0074
#define OMAP54XX_PM_ABE_TIMER7_WKDEP_OFFSET			0x0078
#define OMAP54XX_RM_ABE_TIMER7_CONTEXT_OFFSET			0x007c
#define OMAP54XX_PM_ABE_TIMER8_WKDEP_OFFSET			0x0080
#define OMAP54XX_RM_ABE_TIMER8_CONTEXT_OFFSET			0x0084
#define OMAP54XX_PM_ABE_WD_TIMER3_WKDEP_OFFSET			0x0088
#define OMAP54XX_RM_ABE_WD_TIMER3_CONTEXT_OFFSET		0x008c

/* PRM.COREAON_PRM register offsets */
#define OMAP54XX_PM_COREAON_SMARTREFLEX_MPU_WKDEP_OFFSET	0x0028
#define OMAP54XX_RM_COREAON_SMARTREFLEX_MPU_CONTEXT_OFFSET	0x002c
#define OMAP54XX_PM_COREAON_SMARTREFLEX_MM_WKDEP_OFFSET		0x0030
#define OMAP54XX_RM_COREAON_SMARTREFLEX_MM_CONTEXT_OFFSET	0x0034
#define OMAP54XX_PM_COREAON_SMARTREFLEX_CORE_WKDEP_OFFSET	0x0038
#define OMAP54XX_RM_COREAON_SMARTREFLEX_CORE_CONTEXT_OFFSET	0x003c

/* PRM.CORE_PRM register offsets */
#define OMAP54XX_PM_CORE_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_CORE_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_L3MAIN1_L3_MAIN_1_CONTEXT_OFFSET		0x0024
#define OMAP54XX_RM_L3MAIN2_L3_MAIN_2_CONTEXT_OFFSET		0x0124
#define OMAP54XX_RM_L3MAIN2_GPMC_CONTEXT_OFFSET			0x012c
#define OMAP54XX_RM_L3MAIN2_OCMC_RAM_CONTEXT_OFFSET		0x0134
#define OMAP54XX_RM_IPU_RSTCTRL_OFFSET				0x0210
#define OMAP54XX_RM_IPU_RSTST_OFFSET				0x0214
#define OMAP54XX_RM_IPU_IPU_CONTEXT_OFFSET			0x0224
#define OMAP54XX_RM_DMA_DMA_SYSTEM_CONTEXT_OFFSET		0x0324
#define OMAP54XX_RM_EMIF_DMM_CONTEXT_OFFSET			0x0424
#define OMAP54XX_RM_EMIF_EMIF_OCP_FW_CONTEXT_OFFSET		0x042c
#define OMAP54XX_RM_EMIF_EMIF1_CONTEXT_OFFSET			0x0434
#define OMAP54XX_RM_EMIF_EMIF2_CONTEXT_OFFSET			0x043c
#define OMAP54XX_RM_EMIF_EMIF_DLL_CONTEXT_OFFSET		0x0444
#define OMAP54XX_RM_C2C_C2C_CONTEXT_OFFSET			0x0524
#define OMAP54XX_RM_C2C_MODEM_ICR_CONTEXT_OFFSET		0x052c
#define OMAP54XX_RM_C2C_C2C_OCP_FW_CONTEXT_OFFSET		0x0534
#define OMAP54XX_RM_L4CFG_L4_CFG_CONTEXT_OFFSET			0x0624
#define OMAP54XX_RM_L4CFG_SPINLOCK_CONTEXT_OFFSET		0x062c
#define OMAP54XX_RM_L4CFG_MAILBOX_CONTEXT_OFFSET		0x0634
#define OMAP54XX_RM_L4CFG_SAR_ROM_CONTEXT_OFFSET		0x063c
#define OMAP54XX_RM_L4CFG_OCP2SCP2_CONTEXT_OFFSET		0x0644
#define OMAP54XX_RM_L3INSTR_L3_MAIN_3_CONTEXT_OFFSET		0x0724
#define OMAP54XX_RM_L3INSTR_L3_INSTR_CONTEXT_OFFSET		0x072c
#define OMAP54XX_RM_L3INSTR_OCP_WP_NOC_CONTEXT_OFFSET		0x0744
#define OMAP54XX_RM_MIPIEXT_LLI_CONTEXT_OFFSET			0x0824
#define OMAP54XX_RM_MIPIEXT_LLI_OCP_FW_CONTEXT_OFFSET		0x082c
#define OMAP54XX_RM_MIPIEXT_MPHY_CONTEXT_OFFSET			0x0834
#define OMAP54XX_PM_L4PER_TIMER10_WKDEP_OFFSET			0x0928
#define OMAP54XX_RM_L4PER_TIMER10_CONTEXT_OFFSET		0x092c
#define OMAP54XX_PM_L4PER_TIMER11_WKDEP_OFFSET			0x0930
#define OMAP54XX_RM_L4PER_TIMER11_CONTEXT_OFFSET		0x0934
#define OMAP54XX_PM_L4PER_TIMER2_WKDEP_OFFSET			0x0938
#define OMAP54XX_RM_L4PER_TIMER2_CONTEXT_OFFSET			0x093c
#define OMAP54XX_PM_L4PER_TIMER3_WKDEP_OFFSET			0x0940
#define OMAP54XX_RM_L4PER_TIMER3_CONTEXT_OFFSET			0x0944
#define OMAP54XX_PM_L4PER_TIMER4_WKDEP_OFFSET			0x0948
#define OMAP54XX_RM_L4PER_TIMER4_CONTEXT_OFFSET			0x094c
#define OMAP54XX_PM_L4PER_TIMER9_WKDEP_OFFSET			0x0950
#define OMAP54XX_RM_L4PER_TIMER9_CONTEXT_OFFSET			0x0954
#define OMAP54XX_RM_L4PER_ELM_CONTEXT_OFFSET			0x095c
#define OMAP54XX_PM_L4PER_GPIO2_WKDEP_OFFSET			0x0960
#define OMAP54XX_RM_L4PER_GPIO2_CONTEXT_OFFSET			0x0964
#define OMAP54XX_PM_L4PER_GPIO3_WKDEP_OFFSET			0x0968
#define OMAP54XX_RM_L4PER_GPIO3_CONTEXT_OFFSET			0x096c
#define OMAP54XX_PM_L4PER_GPIO4_WKDEP_OFFSET			0x0970
#define OMAP54XX_RM_L4PER_GPIO4_CONTEXT_OFFSET			0x0974
#define OMAP54XX_PM_L4PER_GPIO5_WKDEP_OFFSET			0x0978
#define OMAP54XX_RM_L4PER_GPIO5_CONTEXT_OFFSET			0x097c
#define OMAP54XX_PM_L4PER_GPIO6_WKDEP_OFFSET			0x0980
#define OMAP54XX_RM_L4PER_GPIO6_CONTEXT_OFFSET			0x0984
#define OMAP54XX_RM_L4PER_HDQ1W_CONTEXT_OFFSET			0x098c
#define OMAP54XX_PM_L4PER_I2C1_WKDEP_OFFSET			0x09a0
#define OMAP54XX_RM_L4PER_I2C1_CONTEXT_OFFSET			0x09a4
#define OMAP54XX_PM_L4PER_I2C2_WKDEP_OFFSET			0x09a8
#define OMAP54XX_RM_L4PER_I2C2_CONTEXT_OFFSET			0x09ac
#define OMAP54XX_PM_L4PER_I2C3_WKDEP_OFFSET			0x09b0
#define OMAP54XX_RM_L4PER_I2C3_CONTEXT_OFFSET			0x09b4
#define OMAP54XX_PM_L4PER_I2C4_WKDEP_OFFSET			0x09b8
#define OMAP54XX_RM_L4PER_I2C4_CONTEXT_OFFSET			0x09bc
#define OMAP54XX_RM_L4PER_L4_PER_CONTEXT_OFFSET			0x09c0
#define OMAP54XX_PM_L4PER_MCSPI1_WKDEP_OFFSET			0x09f0
#define OMAP54XX_RM_L4PER_MCSPI1_CONTEXT_OFFSET			0x09f4
#define OMAP54XX_PM_L4PER_MCSPI2_WKDEP_OFFSET			0x09f8
#define OMAP54XX_RM_L4PER_MCSPI2_CONTEXT_OFFSET			0x09fc
#define OMAP54XX_PM_L4PER_MCSPI3_WKDEP_OFFSET			0x0a00
#define OMAP54XX_RM_L4PER_MCSPI3_CONTEXT_OFFSET			0x0a04
#define OMAP54XX_PM_L4PER_MCSPI4_WKDEP_OFFSET			0x0a08
#define OMAP54XX_RM_L4PER_MCSPI4_CONTEXT_OFFSET			0x0a0c
#define OMAP54XX_PM_L4PER_GPIO7_WKDEP_OFFSET			0x0a10
#define OMAP54XX_RM_L4PER_GPIO7_CONTEXT_OFFSET			0x0a14
#define OMAP54XX_PM_L4PER_GPIO8_WKDEP_OFFSET			0x0a18
#define OMAP54XX_RM_L4PER_GPIO8_CONTEXT_OFFSET			0x0a1c
#define OMAP54XX_PM_L4PER_MMC3_WKDEP_OFFSET			0x0a20
#define OMAP54XX_RM_L4PER_MMC3_CONTEXT_OFFSET			0x0a24
#define OMAP54XX_PM_L4PER_MMC4_WKDEP_OFFSET			0x0a28
#define OMAP54XX_RM_L4PER_MMC4_CONTEXT_OFFSET			0x0a2c
#define OMAP54XX_PM_L4PER_UART1_WKDEP_OFFSET			0x0a40
#define OMAP54XX_RM_L4PER_UART1_CONTEXT_OFFSET			0x0a44
#define OMAP54XX_PM_L4PER_UART2_WKDEP_OFFSET			0x0a48
#define OMAP54XX_RM_L4PER_UART2_CONTEXT_OFFSET			0x0a4c
#define OMAP54XX_PM_L4PER_UART3_WKDEP_OFFSET			0x0a50
#define OMAP54XX_RM_L4PER_UART3_CONTEXT_OFFSET			0x0a54
#define OMAP54XX_RM_L4PER_UART4_CONTEXT_OFFSET			0x0a58
#define OMAP54XX_PM_L4PER_UART4_WKDEP_OFFSET			0x0a5c
#define OMAP54XX_PM_L4PER_MMC5_WKDEP_OFFSET			0x0a60
#define OMAP54XX_RM_L4PER_MMC5_CONTEXT_OFFSET			0x0a64
#define OMAP54XX_PM_L4PER_I2C5_WKDEP_OFFSET			0x0a68
#define OMAP54XX_RM_L4PER_I2C5_CONTEXT_OFFSET			0x0a6c
#define OMAP54XX_PM_L4PER_UART5_WKDEP_OFFSET			0x0a70
#define OMAP54XX_RM_L4PER_UART5_CONTEXT_OFFSET			0x0a74
#define OMAP54XX_PM_L4PER_UART6_WKDEP_OFFSET			0x0a78
#define OMAP54XX_RM_L4PER_UART6_CONTEXT_OFFSET			0x0a7c
#define OMAP54XX_RM_L4SEC_AES1_CONTEXT_OFFSET			0x0aa4
#define OMAP54XX_RM_L4SEC_AES2_CONTEXT_OFFSET			0x0aac
#define OMAP54XX_RM_L4SEC_DES3DES_CONTEXT_OFFSET		0x0ab4
#define OMAP54XX_RM_L4SEC_FPKA_CONTEXT_OFFSET			0x0abc
#define OMAP54XX_RM_L4SEC_RNG_CONTEXT_OFFSET			0x0ac4
#define OMAP54XX_RM_L4SEC_SHA2MD5_CONTEXT_OFFSET		0x0acc
#define OMAP54XX_RM_L4SEC_DMA_CRYPTO_CONTEXT_OFFSET		0x0adc

/* PRM.IVA_PRM register offsets */
#define OMAP54XX_PM_IVA_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_IVA_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_IVA_RSTCTRL_OFFSET				0x0010
#define OMAP54XX_RM_IVA_RSTST_OFFSET				0x0014
#define OMAP54XX_RM_IVA_IVA_CONTEXT_OFFSET			0x0024
#define OMAP54XX_RM_IVA_SL2_CONTEXT_OFFSET			0x002c

/* PRM.CAM_PRM register offsets */
#define OMAP54XX_PM_CAM_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_CAM_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_CAM_ISS_CONTEXT_OFFSET			0x0024
#define OMAP54XX_RM_CAM_FDIF_CONTEXT_OFFSET			0x002c
#define OMAP54XX_RM_CAM_CAL_CONTEXT_OFFSET			0x0034

/* PRM.DSS_PRM register offsets */
#define OMAP54XX_PM_DSS_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_DSS_PWRSTST_OFFSET				0x0004
#define OMAP54XX_PM_DSS_DSS_WKDEP_OFFSET			0x0020
#define OMAP54XX_RM_DSS_DSS_CONTEXT_OFFSET			0x0024
#define OMAP54XX_RM_DSS_BB2D_CONTEXT_OFFSET			0x0034

/* PRM.GPU_PRM register offsets */
#define OMAP54XX_PM_GPU_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_GPU_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_GPU_GPU_CONTEXT_OFFSET			0x0024

/* PRM.L3INIT_PRM register offsets */
#define OMAP54XX_PM_L3INIT_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_L3INIT_PWRSTST_OFFSET			0x0004
#define OMAP54XX_PM_L3INIT_MMC1_WKDEP_OFFSET			0x0028
#define OMAP54XX_RM_L3INIT_MMC1_CONTEXT_OFFSET			0x002c
#define OMAP54XX_PM_L3INIT_MMC2_WKDEP_OFFSET			0x0030
#define OMAP54XX_RM_L3INIT_MMC2_CONTEXT_OFFSET			0x0034
#define OMAP54XX_PM_L3INIT_HSI_WKDEP_OFFSET			0x0038
#define OMAP54XX_RM_L3INIT_HSI_CONTEXT_OFFSET			0x003c
#define OMAP54XX_PM_L3INIT_UNIPRO2_WKDEP_OFFSET			0x0040
#define OMAP54XX_RM_L3INIT_UNIPRO2_CONTEXT_OFFSET		0x0044
#define OMAP54XX_PM_L3INIT_USB_HOST_HS_WKDEP_OFFSET		0x0058
#define OMAP54XX_RM_L3INIT_USB_HOST_HS_CONTEXT_OFFSET		0x005c
#define OMAP54XX_PM_L3INIT_USB_TLL_HS_WKDEP_OFFSET		0x0068
#define OMAP54XX_RM_L3INIT_USB_TLL_HS_CONTEXT_OFFSET		0x006c
#define OMAP54XX_RM_L3INIT_IEEE1500_2_OCP_CONTEXT_OFFSET	0x007c
#define OMAP54XX_PM_L3INIT_SATA_WKDEP_OFFSET			0x0088
#define OMAP54XX_RM_L3INIT_SATA_CONTEXT_OFFSET			0x008c
#define OMAP54XX_RM_L3INIT_OCP2SCP1_CONTEXT_OFFSET		0x00e4
#define OMAP54XX_RM_L3INIT_OCP2SCP3_CONTEXT_OFFSET		0x00ec
#define OMAP54XX_PM_L3INIT_USB_OTG_SS_WKDEP_OFFSET		0x00f0
#define OMAP54XX_RM_L3INIT_USB_OTG_SS_CONTEXT_OFFSET		0x00f4

/* PRM.CUSTEFUSE_PRM register offsets */
#define OMAP54XX_PM_CUSTEFUSE_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_CUSTEFUSE_PWRSTST_OFFSET			0x0004
#define OMAP54XX_RM_CUSTEFUSE_EFUSE_CTRL_CUST_CONTEXT_OFFSET	0x0024

/* PRM.WKUPAON_PRM register offsets */
#define OMAP54XX_RM_WKUPAON_L4_WKUP_CONTEXT_OFFSET		0x0024
#define OMAP54XX_RM_WKUPAON_WD_TIMER1_CONTEXT_OFFSET		0x002c
#define OMAP54XX_PM_WKUPAON_WD_TIMER2_WKDEP_OFFSET		0x0030
#define OMAP54XX_RM_WKUPAON_WD_TIMER2_CONTEXT_OFFSET		0x0034
#define OMAP54XX_PM_WKUPAON_GPIO1_WKDEP_OFFSET			0x0038
#define OMAP54XX_RM_WKUPAON_GPIO1_CONTEXT_OFFSET		0x003c
#define OMAP54XX_PM_WKUPAON_TIMER1_WKDEP_OFFSET			0x0040
#define OMAP54XX_RM_WKUPAON_TIMER1_CONTEXT_OFFSET		0x0044
#define OMAP54XX_PM_WKUPAON_TIMER12_WKDEP_OFFSET		0x0048
#define OMAP54XX_RM_WKUPAON_TIMER12_CONTEXT_OFFSET		0x004c
#define OMAP54XX_RM_WKUPAON_COUNTER_32K_CONTEXT_OFFSET		0x0054
#define OMAP54XX_RM_WKUPAON_SAR_RAM_CONTEXT_OFFSET		0x0064
#define OMAP54XX_PM_WKUPAON_KBD_WKDEP_OFFSET			0x0078
#define OMAP54XX_RM_WKUPAON_KBD_CONTEXT_OFFSET			0x007c

/* PRM.WKUPAON_CM register offsets */
#define OMAP54XX_CM_WKUPAON_CLKSTCTRL_OFFSET			0x0000
#define OMAP54XX_CM_WKUPAON_L4_WKUP_CLKCTRL_OFFSET		0x0020
#define OMAP54XX_CM_WKUPAON_L4_WKUP_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0020)
#define OMAP54XX_CM_WKUPAON_WD_TIMER1_CLKCTRL_OFFSET		0x0028
#define OMAP54XX_CM_WKUPAON_WD_TIMER1_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0028)
#define OMAP54XX_CM_WKUPAON_WD_TIMER2_CLKCTRL_OFFSET		0x0030
#define OMAP54XX_CM_WKUPAON_WD_TIMER2_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0030)
#define OMAP54XX_CM_WKUPAON_GPIO1_CLKCTRL_OFFSET		0x0038
#define OMAP54XX_CM_WKUPAON_GPIO1_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0038)
#define OMAP54XX_CM_WKUPAON_TIMER1_CLKCTRL_OFFSET		0x0040
#define OMAP54XX_CM_WKUPAON_TIMER1_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0040)
#define OMAP54XX_CM_WKUPAON_TIMER12_CLKCTRL_OFFSET		0x0048
#define OMAP54XX_CM_WKUPAON_TIMER12_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0048)
#define OMAP54XX_CM_WKUPAON_COUNTER_32K_CLKCTRL_OFFSET		0x0050
#define OMAP54XX_CM_WKUPAON_COUNTER_32K_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0050)
#define OMAP54XX_CM_WKUPAON_SAR_RAM_CLKCTRL_OFFSET		0x0060
#define OMAP54XX_CM_WKUPAON_SAR_RAM_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0060)
#define OMAP54XX_CM_WKUPAON_KBD_CLKCTRL_OFFSET			0x0078
#define OMAP54XX_CM_WKUPAON_KBD_CLKCTRL				OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0078)
#define OMAP54XX_CM_WKUPAON_SCRM_CLKCTRL_OFFSET			0x0090
#define OMAP54XX_CM_WKUPAON_SCRM_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0090)
#define OMAP54XX_CM_WKUPAON_IO_SRCOMP_CLKCTRL_OFFSET		0x0098
#define OMAP54XX_CM_WKUPAON_IO_SRCOMP_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_WKUPAON_CM_INST, 0x0098)

/* PRM.EMU_PRM register offsets */
#define OMAP54XX_PM_EMU_PWRSTCTRL_OFFSET			0x0000
#define OMAP54XX_PM_EMU_PWRSTST_OFFSET				0x0004
#define OMAP54XX_RM_EMU_DEBUGSS_CONTEXT_OFFSET			0x0024

/* PRM.EMU_CM register offsets */
#define OMAP54XX_CM_EMU_CLKSTCTRL_OFFSET			0x0000
#define OMAP54XX_CM_EMU_DYNAMICDEP_OFFSET			0x0008
#define OMAP54XX_CM_EMU_DEBUGSS_CLKCTRL_OFFSET			0x0020
#define OMAP54XX_CM_EMU_DEBUGSS_CLKCTRL				OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_EMU_CM_INST, 0x0020)
#define OMAP54XX_CM_EMU_MPU_EMU_DBG_CLKCTRL_OFFSET		0x0028
#define OMAP54XX_CM_EMU_MPU_EMU_DBG_CLKCTRL			OMAP54XX_PRM_REGADDR(OMAP54XX_PRM_EMU_CM_INST, 0x0028)

/* PRM.DEVICE_PRM register offsets */
#define OMAP54XX_PRM_RSTCTRL_OFFSET				0x0000
#define OMAP54XX_PRM_RSTST_OFFSET				0x0004
#define OMAP54XX_PRM_RSTTIME_OFFSET				0x0008
#define OMAP54XX_PRM_CLKREQCTRL_OFFSET				0x000c
#define OMAP54XX_PRM_VOLTCTRL_OFFSET				0x0010
#define OMAP54XX_PRM_PWRREQCTRL_OFFSET				0x0014
#define OMAP54XX_PRM_PSCON_COUNT_OFFSET				0x0018
#define OMAP54XX_PRM_IO_COUNT_OFFSET				0x001c
#define OMAP54XX_PRM_IO_PMCTRL_OFFSET				0x0020
#define OMAP54XX_PRM_VOLTSETUP_WARMRESET_OFFSET			0x0024
#define OMAP54XX_PRM_VOLTSETUP_CORE_OFF_OFFSET			0x0028
#define OMAP54XX_PRM_VOLTSETUP_MPU_OFF_OFFSET			0x002c
#define OMAP54XX_PRM_VOLTSETUP_MM_OFF_OFFSET			0x0030
#define OMAP54XX_PRM_VOLTSETUP_CORE_RET_SLEEP_OFFSET		0x0034
#define OMAP54XX_PRM_VOLTSETUP_MPU_RET_SLEEP_OFFSET		0x0038
#define OMAP54XX_PRM_VOLTSETUP_MM_RET_SLEEP_OFFSET		0x003c
#define OMAP54XX_PRM_VP_CORE_CONFIG_OFFSET			0x0040
#define OMAP54XX_PRM_VP_CORE_STATUS_OFFSET			0x0044
#define OMAP54XX_PRM_VP_CORE_VLIMITTO_OFFSET			0x0048
#define OMAP54XX_PRM_VP_CORE_VOLTAGE_OFFSET			0x004c
#define OMAP54XX_PRM_VP_CORE_VSTEPMAX_OFFSET			0x0050
#define OMAP54XX_PRM_VP_CORE_VSTEPMIN_OFFSET			0x0054
#define OMAP54XX_PRM_VP_MPU_CONFIG_OFFSET			0x0058
#define OMAP54XX_PRM_VP_MPU_STATUS_OFFSET			0x005c
#define OMAP54XX_PRM_VP_MPU_VLIMITTO_OFFSET			0x0060
#define OMAP54XX_PRM_VP_MPU_VOLTAGE_OFFSET			0x0064
#define OMAP54XX_PRM_VP_MPU_VSTEPMAX_OFFSET			0x0068
#define OMAP54XX_PRM_VP_MPU_VSTEPMIN_OFFSET			0x006c
#define OMAP54XX_PRM_VP_MM_CONFIG_OFFSET			0x0070
#define OMAP54XX_PRM_VP_MM_STATUS_OFFSET			0x0074
#define OMAP54XX_PRM_VP_MM_VLIMITTO_OFFSET			0x0078
#define OMAP54XX_PRM_VP_MM_VOLTAGE_OFFSET			0x007c
#define OMAP54XX_PRM_VP_MM_VSTEPMAX_OFFSET			0x0080
#define OMAP54XX_PRM_VP_MM_VSTEPMIN_OFFSET			0x0084
#define OMAP54XX_PRM_VC_SMPS_CORE_CONFIG_OFFSET			0x0088
#define OMAP54XX_PRM_VC_SMPS_MM_CONFIG_OFFSET			0x008c
#define OMAP54XX_PRM_VC_SMPS_MPU_CONFIG_OFFSET			0x0090
#define OMAP54XX_PRM_VC_VAL_CMD_VDD_CORE_L_OFFSET		0x0094
#define OMAP54XX_PRM_VC_VAL_CMD_VDD_MM_L_OFFSET			0x0098
#define OMAP54XX_PRM_VC_VAL_CMD_VDD_MPU_L_OFFSET		0x009c
#define OMAP54XX_PRM_VC_VAL_BYPASS_OFFSET			0x00a0
#define OMAP54XX_PRM_VC_CORE_ERRST_OFFSET			0x00a4
#define OMAP54XX_PRM_VC_MM_ERRST_OFFSET				0x00a8
#define OMAP54XX_PRM_VC_MPU_ERRST_OFFSET			0x00ac
#define OMAP54XX_PRM_VC_BYPASS_ERRST_OFFSET			0x00b0
#define OMAP54XX_PRM_VC_CFG_I2C_MODE_OFFSET			0x00b4
#define OMAP54XX_PRM_VC_CFG_I2C_CLK_OFFSET			0x00b8
#define OMAP54XX_PRM_SRAM_COUNT_OFFSET				0x00bc
#define OMAP54XX_PRM_SRAM_WKUP_SETUP_OFFSET			0x00c0
#define OMAP54XX_PRM_SLDO_CORE_SETUP_OFFSET			0x00c4
#define OMAP54XX_PRM_SLDO_CORE_CTRL_OFFSET			0x00c8
#define OMAP54XX_PRM_SLDO_MPU_SETUP_OFFSET			0x00cc
#define OMAP54XX_PRM_SLDO_MPU_CTRL_OFFSET			0x00d0
#define OMAP54XX_PRM_SLDO_MM_SETUP_OFFSET			0x00d4
#define OMAP54XX_PRM_SLDO_MM_CTRL_OFFSET			0x00d8
#define OMAP54XX_PRM_ABBLDO_MPU_SETUP_OFFSET			0x00dc
#define OMAP54XX_PRM_ABBLDO_MPU_CTRL_OFFSET			0x00e0
#define OMAP54XX_PRM_ABBLDO_MM_SETUP_OFFSET			0x00e4
#define OMAP54XX_PRM_ABBLDO_MM_CTRL_OFFSET			0x00e8
#define OMAP54XX_PRM_BANDGAP_SETUP_OFFSET			0x00ec
#define OMAP54XX_PRM_DEVICE_OFF_CTRL_OFFSET			0x00f0
#define OMAP54XX_PRM_PHASE1_CNDP_OFFSET				0x00f4
#define OMAP54XX_PRM_PHASE2A_CNDP_OFFSET			0x00f8
#define OMAP54XX_PRM_PHASE2B_CNDP_OFFSET			0x00fc
#define OMAP54XX_PRM_MODEM_IF_CTRL_OFFSET			0x0100
#define OMAP54XX_PRM_VOLTST_MPU_OFFSET				0x0110
#define OMAP54XX_PRM_VOLTST_MM_OFFSET				0x0114

#endif
