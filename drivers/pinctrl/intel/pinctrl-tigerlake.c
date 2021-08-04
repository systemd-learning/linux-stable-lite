// SPDX-License-Identifier: GPL-2.0
/*
 * Intel Tiger Lake PCH pinctrl/GPIO driver
 *
 * Copyright (C) 2019 - 2020, Intel Corporation
 * Authors: Andy Shevchenko <andriy.shevchenko@linux.intel.com>
 *          Mika Westerberg <mika.westerberg@linux.intel.com>
 */

#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/platform_device.h>

#include <linux/pinctrl/pinctrl.h>

#include "pinctrl-intel.h"

#define TGL_PAD_OWN		0x020
#define TGL_LP_PADCFGLOCK	0x080
#define TGL_H_PADCFGLOCK	0x090
#define TGL_LP_HOSTSW_OWN	0x0b0
#define TGL_H_HOSTSW_OWN	0x0c0
#define TGL_GPI_IS		0x100
#define TGL_GPI_IE		0x120

#define TGL_GPP(r, s, e, g)				\
	{						\
		.reg_num = (r),				\
		.base = (s),				\
		.size = ((e) - (s) + 1),		\
		.gpio_base = (g),			\
	}

#define TGL_COMMUNITY(b, s, e, pl, ho, g)		\
	{						\
		.barno = (b),				\
		.padown_offset = TGL_PAD_OWN,		\
		.padcfglock_offset = (pl),		\
		.hostown_offset = (ho),			\
		.is_offset = TGL_GPI_IS,		\
		.ie_offset = TGL_GPI_IE,		\
		.pin_base = (s),			\
		.npins = ((e) - (s) + 1),		\
		.gpps = (g),				\
		.ngpps = ARRAY_SIZE(g),			\
	}

#define TGL_LP_COMMUNITY(b, s, e, g)			\
	TGL_COMMUNITY(b, s, e, TGL_LP_PADCFGLOCK, TGL_LP_HOSTSW_OWN, g)

#define TGL_H_COMMUNITY(b, s, e, g)			\
	TGL_COMMUNITY(b, s, e, TGL_H_PADCFGLOCK, TGL_H_HOSTSW_OWN, g)

/* Tiger Lake-LP */
static const struct pinctrl_pin_desc tgllp_pins[] = {
	/* GPP_B */
	PINCTRL_PIN(0, "CORE_VID_0"),
	PINCTRL_PIN(1, "CORE_VID_1"),
	PINCTRL_PIN(2, "VRALERTB"),
	PINCTRL_PIN(3, "CPU_GP_2"),
	PINCTRL_PIN(4, "CPU_GP_3"),
	PINCTRL_PIN(5, "ISH_I2C0_SDA"),
	PINCTRL_PIN(6, "ISH_I2C0_SCL"),
	PINCTRL_PIN(7, "ISH_I2C1_SDA"),
	PINCTRL_PIN(8, "ISH_I2C1_SCL"),
	PINCTRL_PIN(9, "I2C5_SDA"),
	PINCTRL_PIN(10, "I2C5_SCL"),
	PINCTRL_PIN(11, "PMCALERTB"),
	PINCTRL_PIN(12, "SLP_S0B"),
	PINCTRL_PIN(13, "PLTRSTB"),
	PINCTRL_PIN(14, "SPKR"),
	PINCTRL_PIN(15, "GSPI0_CS0B"),
	PINCTRL_PIN(16, "GSPI0_CLK"),
	PINCTRL_PIN(17, "GSPI0_MISO"),
	PINCTRL_PIN(18, "GSPI0_MOSI"),
	PINCTRL_PIN(19, "GSPI1_CS0B"),
	PINCTRL_PIN(20, "GSPI1_CLK"),
	PINCTRL_PIN(21, "GSPI1_MISO"),
	PINCTRL_PIN(22, "GSPI1_MOSI"),
	PINCTRL_PIN(23, "SML1ALERTB"),
	PINCTRL_PIN(24, "GSPI0_CLK_LOOPBK"),
	PINCTRL_PIN(25, "GSPI1_CLK_LOOPBK"),
	/* GPP_T */
	PINCTRL_PIN(26, "I2C6_SDA"),
	PINCTRL_PIN(27, "I2C6_SCL"),
	PINCTRL_PIN(28, "I2C7_SDA"),
	PINCTRL_PIN(29, "I2C7_SCL"),
	PINCTRL_PIN(30, "UART4_RXD"),
	PINCTRL_PIN(31, "UART4_TXD"),
	PINCTRL_PIN(32, "UART4_RTSB"),
	PINCTRL_PIN(33, "UART4_CTSB"),
	PINCTRL_PIN(34, "UART5_RXD"),
	PINCTRL_PIN(35, "UART5_TXD"),
	PINCTRL_PIN(36, "UART5_RTSB"),
	PINCTRL_PIN(37, "UART5_CTSB"),
	PINCTRL_PIN(38, "UART6_RXD"),
	PINCTRL_PIN(39, "UART6_TXD"),
	PINCTRL_PIN(40, "UART6_RTSB"),
	PINCTRL_PIN(41, "UART6_CTSB"),
	/* GPP_A */
	PINCTRL_PIN(42, "ESPI_IO_0"),
	PINCTRL_PIN(43, "ESPI_IO_1"),
	PINCTRL_PIN(44, "ESPI_IO_2"),
	PINCTRL_PIN(45, "ESPI_IO_3"),
	PINCTRL_PIN(46, "ESPI_CSB"),
	PINCTRL_PIN(47, "ESPI_CLK"),
	PINCTRL_PIN(48, "ESPI_RESETB"),
	PINCTRL_PIN(49, "I2S2_SCLK"),
	PINCTRL_PIN(50, "I2S2_SFRM"),
	PINCTRL_PIN(51, "I2S2_TXD"),
	PINCTRL_PIN(52, "I2S2_RXD"),
	PINCTRL_PIN(53, "PMC_I2C_SDA"),
	PINCTRL_PIN(54, "SATAXPCIE_1"),
	PINCTRL_PIN(55, "PMC_I2C_SCL"),
	PINCTRL_PIN(56, "USB2_OCB_1"),
	PINCTRL_PIN(57, "USB2_OCB_2"),
	PINCTRL_PIN(58, "USB2_OCB_3"),
	PINCTRL_PIN(59, "DDSP_HPD_C"),
	PINCTRL_PIN(60, "DDSP_HPD_B"),
	PINCTRL_PIN(61, "DDSP_HPD_1"),
	PINCTRL_PIN(62, "DDSP_HPD_2"),
	PINCTRL_PIN(63, "GPPC_A_21"),
	PINCTRL_PIN(64, "GPPC_A_22"),
	PINCTRL_PIN(65, "I2S1_SCLK"),
	PINCTRL_PIN(66, "ESPI_CLK_LOOPBK"),
	/* GPP_S */
	PINCTRL_PIN(67, "SNDW0_CLK"),
	PINCTRL_PIN(68, "SNDW0_DATA"),
	PINCTRL_PIN(69, "SNDW1_CLK"),
	PINCTRL_PIN(70, "SNDW1_DATA"),
	PINCTRL_PIN(71, "SNDW2_CLK"),
	PINCTRL_PIN(72, "SNDW2_DATA"),
	PINCTRL_PIN(73, "SNDW3_CLK"),
	PINCTRL_PIN(74, "SNDW3_DATA"),
	/* GPP_H */
	PINCTRL_PIN(75, "GPPC_H_0"),
	PINCTRL_PIN(76, "GPPC_H_1"),
	PINCTRL_PIN(77, "GPPC_H_2"),
	PINCTRL_PIN(78, "SX_EXIT_HOLDOFFB"),
	PINCTRL_PIN(79, "I2C2_SDA"),
	PINCTRL_PIN(80, "I2C2_SCL"),
	PINCTRL_PIN(81, "I2C3_SDA"),
	PINCTRL_PIN(82, "I2C3_SCL"),
	PINCTRL_PIN(83, "I2C4_SDA"),
	PINCTRL_PIN(84, "I2C4_SCL"),
	PINCTRL_PIN(85, "SRCCLKREQB_4"),
	PINCTRL_PIN(86, "SRCCLKREQB_5"),
	PINCTRL_PIN(87, "M2_SKT2_CFG_0"),
	PINCTRL_PIN(88, "M2_SKT2_CFG_1"),
	PINCTRL_PIN(89, "M2_SKT2_CFG_2"),
	PINCTRL_PIN(90, "M2_SKT2_CFG_3"),
	PINCTRL_PIN(91, "DDPB_CTRLCLK"),
	PINCTRL_PIN(92, "DDPB_CTRLDATA"),
	PINCTRL_PIN(93, "CPU_C10_GATEB"),
	PINCTRL_PIN(94, "TIME_SYNC_0"),
	PINCTRL_PIN(95, "IMGCLKOUT_1"),
	PINCTRL_PIN(96, "IMGCLKOUT_2"),
	PINCTRL_PIN(97, "IMGCLKOUT_3"),
	PINCTRL_PIN(98, "IMGCLKOUT_4"),
	/* GPP_D */
	PINCTRL_PIN(99, "ISH_GP_0"),
	PINCTRL_PIN(100, "ISH_GP_1"),
	PINCTRL_PIN(101, "ISH_GP_2"),
	PINCTRL_PIN(102, "ISH_GP_3"),
	PINCTRL_PIN(103, "IMGCLKOUT_0"),
	PINCTRL_PIN(104, "SRCCLKREQB_0"),
	PINCTRL_PIN(105, "SRCCLKREQB_1"),
	PINCTRL_PIN(106, "SRCCLKREQB_2"),
	PINCTRL_PIN(107, "SRCCLKREQB_3"),
	PINCTRL_PIN(108, "ISH_SPI_CSB"),
	PINCTRL_PIN(109, "ISH_SPI_CLK"),
	PINCTRL_PIN(110, "ISH_SPI_MISO"),
	PINCTRL_PIN(111, "ISH_SPI_MOSI"),
	PINCTRL_PIN(112, "ISH_UART0_RXD"),
	PINCTRL_PIN(113, "ISH_UART0_TXD"),
	PINCTRL_PIN(114, "ISH_UART0_RTSB"),
	PINCTRL_PIN(115, "ISH_UART0_CTSB"),
	PINCTRL_PIN(116, "ISH_GP_4"),
	PINCTRL_PIN(117, "ISH_GP_5"),
	PINCTRL_PIN(118, "I2S_MCLK1_OUT"),
	PINCTRL_PIN(119, "GSPI2_CLK_LOOPBK"),
	/* GPP_U */
	PINCTRL_PIN(120, "UART3_RXD"),
	PINCTRL_PIN(121, "UART3_TXD"),
	PINCTRL_PIN(122, "UART3_RTSB"),
	PINCTRL_PIN(123, "UART3_CTSB"),
	PINCTRL_PIN(124, "GSPI3_CS0B"),
	PINCTRL_PIN(125, "GSPI3_CLK"),
	PINCTRL_PIN(126, "GSPI3_MISO"),
	PINCTRL_PIN(127, "GSPI3_MOSI"),
	PINCTRL_PIN(128, "GSPI4_CS0B"),
	PINCTRL_PIN(129, "GSPI4_CLK"),
	PINCTRL_PIN(130, "GSPI4_MISO"),
	PINCTRL_PIN(131, "GSPI4_MOSI"),
	PINCTRL_PIN(132, "GSPI5_CS0B"),
	PINCTRL_PIN(133, "GSPI5_CLK"),
	PINCTRL_PIN(134, "GSPI5_MISO"),
	PINCTRL_PIN(135, "GSPI5_MOSI"),
	PINCTRL_PIN(136, "GSPI6_CS0B"),
	PINCTRL_PIN(137, "GSPI6_CLK"),
	PINCTRL_PIN(138, "GSPI6_MISO"),
	PINCTRL_PIN(139, "GSPI6_MOSI"),
	PINCTRL_PIN(140, "GSPI3_CLK_LOOPBK"),
	PINCTRL_PIN(141, "GSPI4_CLK_LOOPBK"),
	PINCTRL_PIN(142, "GSPI5_CLK_LOOPBK"),
	PINCTRL_PIN(143, "GSPI6_CLK_LOOPBK"),
	/* vGPIO */
	PINCTRL_PIN(144, "CNV_BTEN"),
	PINCTRL_PIN(145, "CNV_BT_HOST_WAKEB"),
	PINCTRL_PIN(146, "CNV_BT_IF_SELECT"),
	PINCTRL_PIN(147, "vCNV_BT_UART_TXD"),
	PINCTRL_PIN(148, "vCNV_BT_UART_RXD"),
	PINCTRL_PIN(149, "vCNV_BT_UART_CTS_B"),
	PINCTRL_PIN(150, "vCNV_BT_UART_RTS_B"),
	PINCTRL_PIN(151, "vCNV_MFUART1_TXD"),
	PINCTRL_PIN(152, "vCNV_MFUART1_RXD"),
	PINCTRL_PIN(153, "vCNV_MFUART1_CTS_B"),
	PINCTRL_PIN(154, "vCNV_MFUART1_RTS_B"),
	PINCTRL_PIN(155, "vUART0_TXD"),
	PINCTRL_PIN(156, "vUART0_RXD"),
	PINCTRL_PIN(157, "vUART0_CTS_B"),
	PINCTRL_PIN(158, "vUART0_RTS_B"),
	PINCTRL_PIN(159, "vISH_UART0_TXD"),
	PINCTRL_PIN(160, "vISH_UART0_RXD"),
	PINCTRL_PIN(161, "vISH_UART0_CTS_B"),
	PINCTRL_PIN(162, "vISH_UART0_RTS_B"),
	PINCTRL_PIN(163, "vCNV_BT_I2S_BCLK"),
	PINCTRL_PIN(164, "vCNV_BT_I2S_WS_SYNC"),
	PINCTRL_PIN(165, "vCNV_BT_I2S_SDO"),
	PINCTRL_PIN(166, "vCNV_BT_I2S_SDI"),
	PINCTRL_PIN(167, "vI2S2_SCLK"),
	PINCTRL_PIN(168, "vI2S2_SFRM"),
	PINCTRL_PIN(169, "vI2S2_TXD"),
	PINCTRL_PIN(170, "vI2S2_RXD"),
	/* GPP_C */
	PINCTRL_PIN(171, "SMBCLK"),
	PINCTRL_PIN(172, "SMBDATA"),
	PINCTRL_PIN(173, "SMBALERTB"),
	PINCTRL_PIN(174, "SML0CLK"),
	PINCTRL_PIN(175, "SML0DATA"),
	PINCTRL_PIN(176, "SML0ALERTB"),
	PINCTRL_PIN(177, "SML1CLK"),
	PINCTRL_PIN(178, "SML1DATA"),
	PINCTRL_PIN(179, "UART0_RXD"),
	PINCTRL_PIN(180, "UART0_TXD"),
	PINCTRL_PIN(181, "UART0_RTSB"),
	PINCTRL_PIN(182, "UART0_CTSB"),
	PINCTRL_PIN(183, "UART1_RXD"),
	PINCTRL_PIN(184, "UART1_TXD"),
	PINCTRL_PIN(185, "UART1_RTSB"),
	PINCTRL_PIN(186, "UART1_CTSB"),
	PINCTRL_PIN(187, "I2C0_SDA"),
	PINCTRL_PIN(188, "I2C0_SCL"),
	PINCTRL_PIN(189, "I2C1_SDA"),
	PINCTRL_PIN(190, "I2C1_SCL"),
	PINCTRL_PIN(191, "UART2_RXD"),
	PINCTRL_PIN(192, "UART2_TXD"),
	PINCTRL_PIN(193, "UART2_RTSB"),
	PINCTRL_PIN(194, "UART2_CTSB"),
	/* GPP_F */
	PINCTRL_PIN(195, "CNV_BRI_DT"),
	PINCTRL_PIN(196, "CNV_BRI_RSP"),
	PINCTRL_PIN(197, "CNV_RGI_DT"),
	PINCTRL_PIN(198, "CNV_RGI_RSP"),
	PINCTRL_PIN(199, "CNV_RF_RESET_B"),
	PINCTRL_PIN(200, "GPPC_F_5"),
	PINCTRL_PIN(201, "CNV_PA_BLANKING"),
	PINCTRL_PIN(202, "GPPC_F_7"),
	PINCTRL_PIN(203, "I2S_MCLK2_INOUT"),
	PINCTRL_PIN(204, "BOOTMPC"),
	PINCTRL_PIN(205, "GPPC_F_10"),
	PINCTRL_PIN(206, "GPPC_F_11"),
	PINCTRL_PIN(207, "GSXDOUT"),
	PINCTRL_PIN(208, "GSXSLOAD"),
	PINCTRL_PIN(209, "GSXDIN"),
	PINCTRL_PIN(210, "GSXSRESETB"),
	PINCTRL_PIN(211, "GSXCLK"),
	PINCTRL_PIN(212, "GMII_MDC"),
	PINCTRL_PIN(213, "GMII_MDIO"),
	PINCTRL_PIN(214, "SRCCLKREQB_6"),
	PINCTRL_PIN(215, "EXT_PWR_GATEB"),
	PINCTRL_PIN(216, "EXT_PWR_GATE2B"),
	PINCTRL_PIN(217, "VNN_CTRL"),
	PINCTRL_PIN(218, "V1P05_CTRL"),
	PINCTRL_PIN(219, "GPPF_CLK_LOOPBACK"),
	/* HVCMOS */
	PINCTRL_PIN(220, "L_BKLTEN"),
	PINCTRL_PIN(221, "L_BKLTCTL"),
	PINCTRL_PIN(222, "L_VDDEN"),
	PINCTRL_PIN(223, "SYS_PWROK"),
	PINCTRL_PIN(224, "SYS_RESETB"),
	PINCTRL_PIN(225, "MLK_RSTB"),
	/* GPP_E */
	PINCTRL_PIN(226, "SATAXPCIE_0"),
	PINCTRL_PIN(227, "SPI1_IO_2"),
	PINCTRL_PIN(228, "SPI1_IO_3"),
	PINCTRL_PIN(229, "CPU_GP_0"),
	PINCTRL_PIN(230, "SATA_DEVSLP_0"),
	PINCTRL_PIN(231, "SATA_DEVSLP_1"),
	PINCTRL_PIN(232, "GPPC_E_6"),
	PINCTRL_PIN(233, "CPU_GP_1"),
	PINCTRL_PIN(234, "SPI1_CS1B"),
	PINCTRL_PIN(235, "USB2_OCB_0"),
	PINCTRL_PIN(236, "SPI1_CSB"),
	PINCTRL_PIN(237, "SPI1_CLK"),
	PINCTRL_PIN(238, "SPI1_MISO_IO_1"),
	PINCTRL_PIN(239, "SPI1_MOSI_IO_0"),
	PINCTRL_PIN(240, "DDSP_HPD_A"),
	PINCTRL_PIN(241, "ISH_GP_6"),
	PINCTRL_PIN(242, "ISH_GP_7"),
	PINCTRL_PIN(243, "GPPC_E_17"),
	PINCTRL_PIN(244, "DDP1_CTRLCLK"),
	PINCTRL_PIN(245, "DDP1_CTRLDATA"),
	PINCTRL_PIN(246, "DDP2_CTRLCLK"),
	PINCTRL_PIN(247, "DDP2_CTRLDATA"),
	PINCTRL_PIN(248, "DDPA_CTRLCLK"),
	PINCTRL_PIN(249, "DDPA_CTRLDATA"),
	PINCTRL_PIN(250, "SPI1_CLK_LOOPBK"),
	/* JTAG */
	PINCTRL_PIN(251, "JTAG_TDO"),
	PINCTRL_PIN(252, "JTAGX"),
	PINCTRL_PIN(253, "PRDYB"),
	PINCTRL_PIN(254, "PREQB"),
	PINCTRL_PIN(255, "CPU_TRSTB"),
	PINCTRL_PIN(256, "JTAG_TDI"),
	PINCTRL_PIN(257, "JTAG_TMS"),
	PINCTRL_PIN(258, "JTAG_TCK"),
	PINCTRL_PIN(259, "DBG_PMODE"),
	/* GPP_R */
	PINCTRL_PIN(260, "HDA_BCLK"),
	PINCTRL_PIN(261, "HDA_SYNC"),
	PINCTRL_PIN(262, "HDA_SDO"),
	PINCTRL_PIN(263, "HDA_SDI_0"),
	PINCTRL_PIN(264, "HDA_RSTB"),
	PINCTRL_PIN(265, "HDA_SDI_1"),
	PINCTRL_PIN(266, "GPP_R_6"),
	PINCTRL_PIN(267, "GPP_R_7"),
	/* SPI */
	PINCTRL_PIN(268, "SPI0_IO_2"),
	PINCTRL_PIN(269, "SPI0_IO_3"),
	PINCTRL_PIN(270, "SPI0_MOSI_IO_0"),
	PINCTRL_PIN(271, "SPI0_MISO_IO_1"),
	PINCTRL_PIN(272, "SPI0_TPM_CSB"),
	PINCTRL_PIN(273, "SPI0_FLASH_0_CSB"),
	PINCTRL_PIN(274, "SPI0_FLASH_1_CSB"),
	PINCTRL_PIN(275, "SPI0_CLK"),
	PINCTRL_PIN(276, "SPI0_CLK_LOOPBK"),
};

static const struct intel_padgroup tgllp_community0_gpps[] = {
	TGL_GPP(0, 0, 25, 0),				/* GPP_B */
	TGL_GPP(1, 26, 41, 32),				/* GPP_T */
	TGL_GPP(2, 42, 66, 64),				/* GPP_A */
};

static const struct intel_padgroup tgllp_community1_gpps[] = {
	TGL_GPP(0, 67, 74, 96),				/* GPP_S */
	TGL_GPP(1, 75, 98, 128),			/* GPP_H */
	TGL_GPP(2, 99, 119, 160),			/* GPP_D */
	TGL_GPP(3, 120, 143, 192),			/* GPP_U */
	TGL_GPP(4, 144, 170, 224),			/* vGPIO */
};

static const struct intel_padgroup tgllp_community4_gpps[] = {
	TGL_GPP(0, 171, 194, 256),			/* GPP_C */
	TGL_GPP(1, 195, 219, 288),			/* GPP_F */
	TGL_GPP(2, 220, 225, INTEL_GPIO_BASE_NOMAP),	/* HVCMOS */
	TGL_GPP(3, 226, 250, 320),			/* GPP_E */
	TGL_GPP(4, 251, 259, INTEL_GPIO_BASE_NOMAP),	/* JTAG */
};

static const struct intel_padgroup tgllp_community5_gpps[] = {
	TGL_GPP(0, 260, 267, 352),			/* GPP_R */
	TGL_GPP(1, 268, 276, INTEL_GPIO_BASE_NOMAP),	/* SPI */
};

static const struct intel_community tgllp_communities[] = {
	TGL_LP_COMMUNITY(0, 0, 66, tgllp_community0_gpps),
	TGL_LP_COMMUNITY(1, 67, 170, tgllp_community1_gpps),
	TGL_LP_COMMUNITY(2, 171, 259, tgllp_community4_gpps),
	TGL_LP_COMMUNITY(3, 260, 276, tgllp_community5_gpps),
};

static const struct intel_pinctrl_soc_data tgllp_soc_data = {
	.pins = tgllp_pins,
	.npins = ARRAY_SIZE(tgllp_pins),
	.communities = tgllp_communities,
	.ncommunities = ARRAY_SIZE(tgllp_communities),
};

/* Tiger Lake-H */
static const struct pinctrl_pin_desc tglh_pins[] = {
	/* GPP_A */
	PINCTRL_PIN(0, "SPI0_IO_2"),
	PINCTRL_PIN(1, "SPI0_IO_3"),
	PINCTRL_PIN(2, "SPI0_MOSI_IO_0"),
	PINCTRL_PIN(3, "SPI0_MISO_IO_1"),
	PINCTRL_PIN(4, "SPI0_TPM_CSB"),
	PINCTRL_PIN(5, "SPI0_FLASH_0_CSB"),
	PINCTRL_PIN(6, "SPI0_FLASH_1_CSB"),
	PINCTRL_PIN(7, "SPI0_CLK"),
	PINCTRL_PIN(8, "ESPI_IO_0"),
	PINCTRL_PIN(9, "ESPI_IO_1"),
	PINCTRL_PIN(10, "ESPI_IO_2"),
	PINCTRL_PIN(11, "ESPI_IO_3"),
	PINCTRL_PIN(12, "ESPI_CS0B"),
	PINCTRL_PIN(13, "ESPI_CLK"),
	PINCTRL_PIN(14, "ESPI_RESETB"),
	PINCTRL_PIN(15, "ESPI_CS1B"),
	PINCTRL_PIN(16, "ESPI_CS2B"),
	PINCTRL_PIN(17, "ESPI_CS3B"),
	PINCTRL_PIN(18, "ESPI_ALERT0B"),
	PINCTRL_PIN(19, "ESPI_ALERT1B"),
	PINCTRL_PIN(20, "ESPI_ALERT2B"),
	PINCTRL_PIN(21, "ESPI_ALERT3B"),
	PINCTRL_PIN(22, "GPPC_A_14"),
	PINCTRL_PIN(23, "SPI0_CLK_LOOPBK"),
	PINCTRL_PIN(24, "ESPI_CLK_LOOPBK"),
	/* GPP_R */
	PINCTRL_PIN(25, "HDA_BCLK"),
	PINCTRL_PIN(26, "HDA_SYNC"),
	PINCTRL_PIN(27, "HDA_SDO"),
	PINCTRL_PIN(28, "HDA_SDI_0"),
	PINCTRL_PIN(29, "HDA_RSTB"),
	PINCTRL_PIN(30, "HDA_SDI_1"),
	PINCTRL_PIN(31, "GPP_R_6"),
	PINCTRL_PIN(32, "GPP_R_7"),
	PINCTRL_PIN(33, "GPP_R_8"),
	PINCTRL_PIN(34, "PCIE_LNK_DOWN"),
	PINCTRL_PIN(35, "ISH_UART0_RTSB"),
	PINCTRL_PIN(36, "SX_EXIT_HOLDOFFB"),
	PINCTRL_PIN(37, "CLKOUT_48"),
	PINCTRL_PIN(38, "ISH_GP_7"),
	PINCTRL_PIN(39, "ISH_GP_0"),
	PINCTRL_PIN(40, "ISH_GP_1"),
	PINCTRL_PIN(41, "ISH_GP_2"),
	PINCTRL_PIN(42, "ISH_GP_3"),
	PINCTRL_PIN(43, "ISH_GP_4"),
	PINCTRL_PIN(44, "ISH_GP_5"),
	/* GPP_B */
	PINCTRL_PIN(45, "GSPI0_CS1B"),
	PINCTRL_PIN(46, "GSPI1_CS1B"),
	PINCTRL_PIN(47, "VRALERTB"),
	PINCTRL_PIN(48, "CPU_GP_2"),
	PINCTRL_PIN(49, "CPU_GP_3"),
	PINCTRL_PIN(50, "SRCCLKREQB_0"),
	PINCTRL_PIN(51, "SRCCLKREQB_1"),
	PINCTRL_PIN(52, "SRCCLKREQB_2"),
	PINCTRL_PIN(53, "SRCCLKREQB_3"),
	PINCTRL_PIN(54, "SRCCLKREQB_4"),
	PINCTRL_PIN(55, "SRCCLKREQB_5"),
	PINCTRL_PIN(56, "I2S_MCLK"),
	PINCTRL_PIN(57, "SLP_S0B"),
	PINCTRL_PIN(58, "PLTRSTB"),
	PINCTRL_PIN(59, "SPKR"),
	PINCTRL_PIN(60, "GSPI0_CS0B"),
	PINCTRL_PIN(61, "GSPI0_CLK"),
	PINCTRL_PIN(62, "GSPI0_MISO"),
	PINCTRL_PIN(63, "GSPI0_MOSI"),
	PINCTRL_PIN(64, "GSPI1_CS0B"),
	PINCTRL_PIN(65, "GSPI1_CLK"),
	PINCTRL_PIN(66, "GSPI1_MISO"),
	PINCTRL_PIN(67, "GSPI1_MOSI"),
	PINCTRL_PIN(68, "SML1ALERTB"),
	PINCTRL_PIN(69, "GSPI0_CLK_LOOPBK"),
	PINCTRL_PIN(70, "GSPI1_CLK_LOOPBK"),
	/* vGPIO_0 */
	PINCTRL_PIN(71, "ESPI_USB_OCB_0"),
	PINCTRL_PIN(72, "ESPI_USB_OCB_1"),
	PINCTRL_PIN(73, "ESPI_USB_OCB_2"),
	PINCTRL_PIN(74, "ESPI_USB_OCB_3"),
	PINCTRL_PIN(75, "USB_CPU_OCB_0"),
	PINCTRL_PIN(76, "USB_CPU_OCB_1"),
	PINCTRL_PIN(77, "USB_CPU_OCB_2"),
	PINCTRL_PIN(78, "USB_CPU_OCB_3"),
	/* GPP_D */
	PINCTRL_PIN(79, "SPI1_CSB"),
	PINCTRL_PIN(80, "SPI1_CLK"),
	PINCTRL_PIN(81, "SPI1_MISO_IO_1"),
	PINCTRL_PIN(82, "SPI1_MOSI_IO_0"),
	PINCTRL_PIN(83, "SML1CLK"),
	PINCTRL_PIN(84, "I2S2_SFRM"),
	PINCTRL_PIN(85, "I2S2_TXD"),
	PINCTRL_PIN(86, "I2S2_RXD"),
	PINCTRL_PIN(87, "I2S2_SCLK"),
	PINCTRL_PIN(88, "SML0CLK"),
	PINCTRL_PIN(89, "SML0DATA"),
	PINCTRL_PIN(90, "GPP_D_11"),
	PINCTRL_PIN(91, "ISH_UART0_CTSB"),
	PINCTRL_PIN(92, "SPI1_IO_2"),
	PINCTRL_PIN(93, "SPI1_IO_3"),
	PINCTRL_PIN(94, "SML1DATA"),
	PINCTRL_PIN(95, "GSPI3_CS0B"),
	PINCTRL_PIN(96, "GSPI3_CLK"),
	PINCTRL_PIN(97, "GSPI3_MISO"),
	PINCTRL_PIN(98, "GSPI3_MOSI"),
	PINCTRL_PIN(99, "UART3_RXD"),
	PINCTRL_PIN(100, "UART3_TXD"),
	PINCTRL_PIN(101, "UART3_RTSB"),
	PINCTRL_PIN(102, "UART3_CTSB"),
	PINCTRL_PIN(103, "SPI1_CLK_LOOPBK"),
	PINCTRL_PIN(104, "GSPI3_CLK_LOOPBK"),
	/* GPP_C */
	PINCTRL_PIN(105, "SMBCLK"),
	PINCTRL_PIN(106, "SMBDATA"),
	PINCTRL_PIN(107, "SMBALERTB"),
	PINCTRL_PIN(108, "ISH_UART0_RXD"),
	PINCTRL_PIN(109, "ISH_UART0_TXD"),
	PINCTRL_PIN(110, "SML0ALERTB"),
	PINCTRL_PIN(111, "ISH_I2C2_SDA"),
	PINCTRL_PIN(112, "ISH_I2C2_SCL"),
	PINCTRL_PIN(113, "UART0_RXD"),
	PINCTRL_PIN(114, "UART0_TXD"),
	PINCTRL_PIN(115, "UART0_RTSB"),
	PINCTRL_PIN(116, "UART0_CTSB"),
	PINCTRL_PIN(117, "UART1_RXD"),
	PINCTRL_PIN(118, "UART1_TXD"),
	PINCTRL_PIN(119, "UART1_RTSB"),
	PINCTRL_PIN(120, "UART1_CTSB"),
	PINCTRL_PIN(121, "I2C0_SDA"),
	PINCTRL_PIN(122, "I2C0_SCL"),
	PINCTRL_PIN(123, "I2C1_SDA"),
	PINCTRL_PIN(124, "I2C1_SCL"),
	PINCTRL_PIN(125, "UART2_RXD"),
	PINCTRL_PIN(126, "UART2_TXD"),
	PINCTRL_PIN(127, "UART2_RTSB"),
	PINCTRL_PIN(128, "UART2_CTSB"),
	/* GPP_S */
	PINCTRL_PIN(129, "SNDW1_CLK"),
	PINCTRL_PIN(130, "SNDW1_DATA"),
	PINCTRL_PIN(131, "SNDW2_CLK"),
	PINCTRL_PIN(132, "SNDW2_DATA"),
	PINCTRL_PIN(133, "SNDW3_CLK"),
	PINCTRL_PIN(134, "SNDW3_DATA"),
	PINCTRL_PIN(135, "SNDW4_CLK"),
	PINCTRL_PIN(136, "SNDW4_DATA"),
	/* GPP_G */
	PINCTRL_PIN(137, "DDPA_CTRLCLK"),
	PINCTRL_PIN(138, "DDPA_CTRLDATA"),
	PINCTRL_PIN(139, "DNX_FORCE_RELOAD"),
	PINCTRL_PIN(140, "GMII_MDC_0"),
	PINCTRL_PIN(141, "GMII_MDIO_0"),
	PINCTRL_PIN(142, "SLP_DRAMB"),
	PINCTRL_PIN(143, "GPPC_G_6"),
	PINCTRL_PIN(144, "GPPC_G_7"),
	PINCTRL_PIN(145, "ISH_SPI_CSB"),
	PINCTRL_PIN(146, "ISH_SPI_CLK"),
	PINCTRL_PIN(147, "ISH_SPI_MISO"),
	PINCTRL_PIN(148, "ISH_SPI_MOSI"),
	PINCTRL_PIN(149, "DDP1_CTRLCLK"),
	PINCTRL_PIN(150, "DDP1_CTRLDATA"),
	PINCTRL_PIN(151, "DDP2_CTRLCLK"),
	PINCTRL_PIN(152, "DDP2_CTRLDATA"),
	PINCTRL_PIN(153, "GSPI2_CLK_LOOPBK"),
	/* vGPIO */
	PINCTRL_PIN(154, "CNV_BTEN"),
	PINCTRL_PIN(155, "CNV_BT_HOST_WAKEB"),
	PINCTRL_PIN(156, "CNV_BT_IF_SELECT"),
	PINCTRL_PIN(157, "vCNV_BT_UART_TXD"),
	PINCTRL_PIN(158, "vCNV_BT_UART_RXD"),
	PINCTRL_PIN(159, "vCNV_BT_UART_CTS_B"),
	PINCTRL_PIN(160, "vCNV_BT_UART_RTS_B"),
	PINCTRL_PIN(161, "vCNV_MFUART1_TXD"),
	PINCTRL_PIN(162, "vCNV_MFUART1_RXD"),
	PINCTRL_PIN(163, "vCNV_MFUART1_CTS_B"),
	PINCTRL_PIN(164, "vCNV_MFUART1_RTS_B"),
	PINCTRL_PIN(165, "vUART0_TXD"),
	PINCTRL_PIN(166, "vUART0_RXD"),
	PINCTRL_PIN(167, "vUART0_CTS_B"),
	PINCTRL_PIN(168, "vUART0_RTS_B"),
	PINCTRL_PIN(169, "vISH_UART0_TXD"),
	PINCTRL_PIN(170, "vISH_UART0_RXD"),
	PINCTRL_PIN(171, "vISH_UART0_CTS_B"),
	PINCTRL_PIN(172, "vISH_UART0_RTS_B"),
	PINCTRL_PIN(173, "vCNV_BT_I2S_BCLK"),
	PINCTRL_PIN(174, "vCNV_BT_I2S_WS_SYNC"),
	PINCTRL_PIN(175, "vCNV_BT_I2S_SDO"),
	PINCTRL_PIN(176, "vCNV_BT_I2S_SDI"),
	PINCTRL_PIN(177, "vI2S2_SCLK"),
	PINCTRL_PIN(178, "vI2S2_SFRM"),
	PINCTRL_PIN(179, "vI2S2_TXD"),
	PINCTRL_PIN(180, "vI2S2_RXD"),
	/* GPP_E */
	PINCTRL_PIN(181, "SATAXPCIE_0"),
	PINCTRL_PIN(182, "SATAXPCIE_1"),
	PINCTRL_PIN(183, "SATAXPCIE_2"),
	PINCTRL_PIN(184, "CPU_GP_0"),
	PINCTRL_PIN(185, "SATA_DEVSLP_0"),
	PINCTRL_PIN(186, "SATA_DEVSLP_1"),
	PINCTRL_PIN(187, "SATA_DEVSLP_2"),
	PINCTRL_PIN(188, "CPU_GP_1"),
	PINCTRL_PIN(189, "SATA_LEDB"),
	PINCTRL_PIN(190, "USB2_OCB_0"),
	PINCTRL_PIN(191, "USB2_OCB_1"),
	PINCTRL_PIN(192, "USB2_OCB_2"),
	PINCTRL_PIN(193, "USB2_OCB_3"),
	/* GPP_F */
	PINCTRL_PIN(194, "SATAXPCIE_3"),
	PINCTRL_PIN(195, "SATAXPCIE_4"),
	PINCTRL_PIN(196, "SATAXPCIE_5"),
	PINCTRL_PIN(197, "SATAXPCIE_6"),
	PINCTRL_PIN(198, "SATAXPCIE_7"),
	PINCTRL_PIN(199, "SATA_DEVSLP_3"),
	PINCTRL_PIN(200, "SATA_DEVSLP_4"),
	PINCTRL_PIN(201, "SATA_DEVSLP_5"),
	PINCTRL_PIN(202, "SATA_DEVSLP_6"),
	PINCTRL_PIN(203, "SATA_DEVSLP_7"),
	PINCTRL_PIN(204, "SATA_SCLOCK"),
	PINCTRL_PIN(205, "SATA_SLOAD"),
	PINCTRL_PIN(206, "SATA_SDATAOUT1"),
	PINCTRL_PIN(207, "SATA_SDATAOUT0"),
	PINCTRL_PIN(208, "PS_ONB"),
	PINCTRL_PIN(209, "M2_SKT2_CFG_0"),
	PINCTRL_PIN(210, "M2_SKT2_CFG_1"),
	PINCTRL_PIN(211, "M2_SKT2_CFG_2"),
	PINCTRL_PIN(212, "M2_SKT2_CFG_3"),
	PINCTRL_PIN(213, "L_VDDEN"),
	PINCTRL_PIN(214, "L_BKLTEN"),
	PINCTRL_PIN(215, "L_BKLTCTL"),
	PINCTRL_PIN(216, "VNN_CTRL"),
	PINCTRL_PIN(217, "GPP_F_23"),
	/* GPP_H */
	PINCTRL_PIN(218, "SRCCLKREQB_6"),
	PINCTRL_PIN(219, "SRCCLKREQB_7"),
	PINCTRL_PIN(220, "SRCCLKREQB_8"),
	PINCTRL_PIN(221, "SRCCLKREQB_9"),
	PINCTRL_PIN(222, "SRCCLKREQB_10"),
	PINCTRL_PIN(223, "SRCCLKREQB_11"),
	PINCTRL_PIN(224, "SRCCLKREQB_12"),
	PINCTRL_PIN(225, "SRCCLKREQB_13"),
	PINCTRL_PIN(226, "SRCCLKREQB_14"),
	PINCTRL_PIN(227, "SRCCLKREQB_15"),
	PINCTRL_PIN(228, "SML2CLK"),
	PINCTRL_PIN(229, "SML2DATA"),
	PINCTRL_PIN(230, "SML2ALERTB"),
	PINCTRL_PIN(231, "SML3CLK"),
	PINCTRL_PIN(232, "SML3DATA"),
	PINCTRL_PIN(233, "SML3ALERTB"),
	PINCTRL_PIN(234, "SML4CLK"),
	PINCTRL_PIN(235, "SML4DATA"),
	PINCTRL_PIN(236, "SML4ALERTB"),
	PINCTRL_PIN(237, "ISH_I2C0_SDA"),
	PINCTRL_PIN(238, "ISH_I2C0_SCL"),
	PINCTRL_PIN(239, "ISH_I2C1_SDA"),
	PINCTRL_PIN(240, "ISH_I2C1_SCL"),
	PINCTRL_PIN(241, "TIME_SYNC_0"),
	/* GPP_J */
	PINCTRL_PIN(242, "CNV_PA_BLANKING"),
	PINCTRL_PIN(243, "CPU_C10_GATEB"),
	PINCTRL_PIN(244, "CNV_BRI_DT"),
	PINCTRL_PIN(245, "CNV_BRI_RSP"),
	PINCTRL_PIN(246, "CNV_RGI_DT"),
	PINCTRL_PIN(247, "CNV_RGI_RSP"),
	PINCTRL_PIN(248, "CNV_MFUART2_RXD"),
	PINCTRL_PIN(249, "CNV_MFUART2_TXD"),
	PINCTRL_PIN(250, "GPP_J_8"),
	PINCTRL_PIN(251, "GPP_J_9"),
	/* GPP_K */
	PINCTRL_PIN(252, "GSXDOUT"),
	PINCTRL_PIN(253, "GSXSLOAD"),
	PINCTRL_PIN(254, "GSXDIN"),
	PINCTRL_PIN(255, "GSXSRESETB"),
	PINCTRL_PIN(256, "GSXCLK"),
	PINCTRL_PIN(257, "ADR_COMPLETE"),
	PINCTRL_PIN(258, "DDSP_HPD_A"),
	PINCTRL_PIN(259, "DDSP_HPD_B"),
	PINCTRL_PIN(260, "CORE_VID_0"),
	PINCTRL_PIN(261, "CORE_VID_1"),
	PINCTRL_PIN(262, "DDSP_HPD_C"),
	PINCTRL_PIN(263, "GPP_K_11"),
	PINCTRL_PIN(264, "SYS_PWROK"),
	PINCTRL_PIN(265, "SYS_RESETB"),
	PINCTRL_PIN(266, "MLK_RSTB"),
	/* GPP_I */
	PINCTRL_PIN(267, "PMCALERTB"),
	PINCTRL_PIN(268, "DDSP_HPD_1"),
	PINCTRL_PIN(269, "DDSP_HPD_2"),
	PINCTRL_PIN(270, "DDSP_HPD_3"),
	PINCTRL_PIN(271, "DDSP_HPD_4"),
	PINCTRL_PIN(272, "DDPB_CTRLCLK"),
	PINCTRL_PIN(273, "DDPB_CTRLDATA"),
	PINCTRL_PIN(274, "DDPC_CTRLCLK"),
	PINCTRL_PIN(275, "DDPC_CTRLDATA"),
	PINCTRL_PIN(276, "FUSA_DIAGTEST_EN"),
	PINCTRL_PIN(277, "FUSA_DIAGTEST_MODE"),
	PINCTRL_PIN(278, "USB2_OCB_4"),
	PINCTRL_PIN(279, "USB2_OCB_5"),
	PINCTRL_PIN(280, "USB2_OCB_6"),
	PINCTRL_PIN(281, "USB2_OCB_7"),
	/* JTAG */
	PINCTRL_PIN(282, "JTAG_TDO"),
	PINCTRL_PIN(283, "JTAGX"),
	PINCTRL_PIN(284, "PRDYB"),
	PINCTRL_PIN(285, "PREQB"),
	PINCTRL_PIN(286, "JTAG_TDI"),
	PINCTRL_PIN(287, "JTAG_TMS"),
	PINCTRL_PIN(288, "JTAG_TCK"),
	PINCTRL_PIN(289, "DBG_PMODE"),
	PINCTRL_PIN(290, "CPU_TRSTB"),
};

static const struct intel_padgroup tglh_community0_gpps[] = {
	TGL_GPP(0, 0, 24, 0),				/* GPP_A */
	TGL_GPP(1, 25, 44, 32),				/* GPP_R */
	TGL_GPP(2, 45, 70, 64),				/* GPP_B */
	TGL_GPP(3, 71, 78, 96),				/* vGPIO_0 */
};

static const struct intel_padgroup tglh_community1_gpps[] = {
	TGL_GPP(0, 79, 104, 128),			/* GPP_D */
	TGL_GPP(1, 105, 128, 160),			/* GPP_C */
	TGL_GPP(2, 129, 136, 192),			/* GPP_S */
	TGL_GPP(3, 137, 153, 224),			/* GPP_G */
	TGL_GPP(4, 154, 180, 256),			/* vGPIO */
};

static const struct intel_padgroup tglh_community3_gpps[] = {
	TGL_GPP(0, 181, 193, 288),			/* GPP_E */
	TGL_GPP(1, 194, 217, 320),			/* GPP_F */
};

static const struct intel_padgroup tglh_community4_gpps[] = {
	TGL_GPP(0, 218, 241, 352),			/* GPP_H */
	TGL_GPP(1, 242, 251, 384),			/* GPP_J */
	TGL_GPP(2, 252, 266, 416),			/* GPP_K */
};

static const struct intel_padgroup tglh_community5_gpps[] = {
	TGL_GPP(0, 267, 281, 448),			/* GPP_I */
	TGL_GPP(1, 282, 290, INTEL_GPIO_BASE_NOMAP),	/* JTAG */
};

static const struct intel_community tglh_communities[] = {
	TGL_H_COMMUNITY(0, 0, 78, tglh_community0_gpps),
	TGL_H_COMMUNITY(1, 79, 180, tglh_community1_gpps),
	TGL_H_COMMUNITY(2, 181, 217, tglh_community3_gpps),
	TGL_H_COMMUNITY(3, 218, 266, tglh_community4_gpps),
	TGL_H_COMMUNITY(4, 267, 290, tglh_community5_gpps),
};

static const struct intel_pinctrl_soc_data tglh_soc_data = {
	.pins = tglh_pins,
	.npins = ARRAY_SIZE(tglh_pins),
	.communities = tglh_communities,
	.ncommunities = ARRAY_SIZE(tglh_communities),
};

static const struct acpi_device_id tgl_pinctrl_acpi_match[] = {
	{ "INT34C5", (kernel_ulong_t)&tgllp_soc_data },
	{ "INT34C6", (kernel_ulong_t)&tglh_soc_data },
	{ }
};
MODULE_DEVICE_TABLE(acpi, tgl_pinctrl_acpi_match);

static INTEL_PINCTRL_PM_OPS(tgl_pinctrl_pm_ops);

static struct platform_driver tgl_pinctrl_driver = {
	.probe = intel_pinctrl_probe_by_hid,
	.driver = {
		.name = "tigerlake-pinctrl",
		.acpi_match_table = tgl_pinctrl_acpi_match,
		.pm = &tgl_pinctrl_pm_ops,
	},
};

module_platform_driver(tgl_pinctrl_driver);

MODULE_AUTHOR("Andy Shevchenko <andriy.shevchenko@linux.intel.com>");
MODULE_AUTHOR("Mika Westerberg <mika.westerberg@linux.intel.com>");
MODULE_DESCRIPTION("Intel Tiger Lake PCH pinctrl/GPIO driver");
MODULE_LICENSE("GPL v2");
