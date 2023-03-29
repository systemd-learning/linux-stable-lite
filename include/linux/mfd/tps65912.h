/*
 * Copyright (C) 2015 Texas Instruments Incorporated - https://www.ti.com/
 *	Andrew F. Davis <afd@ti.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether expressed or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * Based on the TPS65218 driver and the previous TPS65912 driver by
 * Margarita Olaya Cabrera <magi@slimlogic.co.uk>
 */

#ifndef __LINUX_MFD_TPS65912_H
#define __LINUX_MFD_TPS65912_H

#include <linux/device.h>
#include <linux/regmap.h>

/* List of registers for TPS65912 */
#define TPS65912_DCDC1_CTRL		0x00
#define TPS65912_DCDC2_CTRL		0x01
#define TPS65912_DCDC3_CTRL		0x02
#define TPS65912_DCDC4_CTRL		0x03
#define TPS65912_DCDC1_OP		0x04
#define TPS65912_DCDC1_AVS		0x05
#define TPS65912_DCDC1_LIMIT		0x06
#define TPS65912_DCDC2_OP		0x07
#define TPS65912_DCDC2_AVS		0x08
#define TPS65912_DCDC2_LIMIT		0x09
#define TPS65912_DCDC3_OP		0x0A
#define TPS65912_DCDC3_AVS		0x0B
#define TPS65912_DCDC3_LIMIT		0x0C
#define TPS65912_DCDC4_OP		0x0D
#define TPS65912_DCDC4_AVS		0x0E
#define TPS65912_DCDC4_LIMIT		0x0F
#define TPS65912_LDO1_OP		0x10
#define TPS65912_LDO1_AVS		0x11
#define TPS65912_LDO1_LIMIT		0x12
#define TPS65912_LDO2_OP		0x13
#define TPS65912_LDO2_AVS		0x14
#define TPS65912_LDO2_LIMIT		0x15
#define TPS65912_LDO3_OP		0x16
#define TPS65912_LDO3_AVS		0x17
#define TPS65912_LDO3_LIMIT		0x18
#define TPS65912_LDO4_OP		0x19
#define TPS65912_LDO4_AVS		0x1A
#define TPS65912_LDO4_LIMIT		0x1B
#define TPS65912_LDO5			0x1C
#define TPS65912_LDO6			0x1D
#define TPS65912_LDO7			0x1E
#define TPS65912_LDO8			0x1F
#define TPS65912_LDO9			0x20
#define TPS65912_LDO10			0x21
#define TPS65912_THRM			0x22
#define TPS65912_CLK32OUT		0x23
#define TPS65912_DEVCTRL		0x24
#define TPS65912_DEVCTRL2		0x25
#define TPS65912_I2C_SPI_CFG		0x26
#define TPS65912_KEEP_ON		0x27
#define TPS65912_KEEP_ON2		0x28
#define TPS65912_SET_OFF1		0x29
#define TPS65912_SET_OFF2		0x2A
#define TPS65912_DEF_VOLT		0x2B
#define TPS65912_DEF_VOLT_MAPPING	0x2C
#define TPS65912_DISCHARGE		0x2D
#define TPS65912_DISCHARGE2		0x2E
#define TPS65912_EN1_SET1		0x2F
#define TPS65912_EN1_SET2		0x30
#define TPS65912_EN2_SET1		0x31
#define TPS65912_EN2_SET2		0x32
#define TPS65912_EN3_SET1		0x33
#define TPS65912_EN3_SET2		0x34
#define TPS65912_EN4_SET1		0x35
#define TPS65912_EN4_SET2		0x36
#define TPS65912_PGOOD			0x37
#define TPS65912_PGOOD2			0x38
#define TPS65912_INT_STS		0x39
#define TPS65912_INT_MSK		0x3A
#define TPS65912_INT_STS2		0x3B
#define TPS65912_INT_MSK2		0x3C
#define TPS65912_INT_STS3		0x3D
#define TPS65912_INT_MSK3		0x3E
#define TPS65912_INT_STS4		0x3F
#define TPS65912_INT_MSK4		0x40
#define TPS65912_GPIO1			0x41
#define TPS65912_GPIO2			0x42
#define TPS65912_GPIO3			0x43
#define TPS65912_GPIO4			0x44
#define TPS65912_GPIO5			0x45
#define TPS65912_VMON			0x46
#define TPS65912_LEDA_CTRL1		0x47
#define TPS65912_LEDA_CTRL2		0x48
#define TPS65912_LEDA_CTRL3		0x49
#define TPS65912_LEDA_CTRL4		0x4A
#define TPS65912_LEDA_CTRL5		0x4B
#define TPS65912_LEDA_CTRL6		0x4C
#define TPS65912_LEDA_CTRL7		0x4D
#define TPS65912_LEDA_CTRL8		0x4E
#define TPS65912_LEDB_CTRL1		0x4F
#define TPS65912_LEDB_CTRL2		0x50
#define TPS65912_LEDB_CTRL3		0x51
#define TPS65912_LEDB_CTRL4		0x52
#define TPS65912_LEDB_CTRL5		0x53
#define TPS65912_LEDB_CTRL6		0x54
#define TPS65912_LEDB_CTRL7		0x55
#define TPS65912_LEDB_CTRL8		0x56
#define TPS65912_LEDC_CTRL1		0x57
#define TPS65912_LEDC_CTRL2		0x58
#define TPS65912_LEDC_CTRL3		0x59
#define TPS65912_LEDC_CTRL4		0x5A
#define TPS65912_LEDC_CTRL5		0x5B
#define TPS65912_LEDC_CTRL6		0x5C
#define TPS65912_LEDC_CTRL7		0x5D
#define TPS65912_LEDC_CTRL8		0x5E
#define TPS65912_LED_RAMP_UP_TIME	0x5F
#define TPS65912_LED_RAMP_DOWN_TIME	0x60
#define TPS65912_LED_SEQ_EN		0x61
#define TPS65912_LOADSWITCH		0x62
#define TPS65912_SPARE			0x63
#define TPS65912_VERNUM			0x64
#define TPS6591X_MAX_REGISTER		0x64

/* INT_STS Register field definitions */
#define TPS65912_INT_STS_PWRHOLD_F	BIT(0)
#define TPS65912_INT_STS_VMON		BIT(1)
#define TPS65912_INT_STS_PWRON		BIT(2)
#define TPS65912_INT_STS_PWRON_LP	BIT(3)
#define TPS65912_INT_STS_PWRHOLD_R	BIT(4)
#define TPS65912_INT_STS_HOTDIE		BIT(5)
#define TPS65912_INT_STS_GPIO1_R	BIT(6)
#define TPS65912_INT_STS_GPIO1_F	BIT(7)

/* INT_STS Register field definitions */
#define TPS65912_INT_STS2_GPIO2_R	BIT(0)
#define TPS65912_INT_STS2_GPIO2_F	BIT(1)
#define TPS65912_INT_STS2_GPIO3_R	BIT(2)
#define TPS65912_INT_STS2_GPIO3_F	BIT(3)
#define TPS65912_INT_STS2_GPIO4_R	BIT(4)
#define TPS65912_INT_STS2_GPIO4_F	BIT(5)
#define TPS65912_INT_STS2_GPIO5_R	BIT(6)
#define TPS65912_INT_STS2_GPIO5_F	BIT(7)

/* INT_STS Register field definitions */
#define TPS65912_INT_STS3_PGOOD_DCDC1	BIT(0)
#define TPS65912_INT_STS3_PGOOD_DCDC2	BIT(1)
#define TPS65912_INT_STS3_PGOOD_DCDC3	BIT(2)
#define TPS65912_INT_STS3_PGOOD_DCDC4	BIT(3)
#define TPS65912_INT_STS3_PGOOD_LDO1	BIT(4)
#define TPS65912_INT_STS3_PGOOD_LDO2	BIT(5)
#define TPS65912_INT_STS3_PGOOD_LDO3	BIT(6)
#define TPS65912_INT_STS3_PGOOD_LDO4	BIT(7)

/* INT_STS Register field definitions */
#define TPS65912_INT_STS4_PGOOD_LDO5	BIT(0)
#define TPS65912_INT_STS4_PGOOD_LDO6	BIT(1)
#define TPS65912_INT_STS4_PGOOD_LDO7	BIT(2)
#define TPS65912_INT_STS4_PGOOD_LDO8	BIT(3)
#define TPS65912_INT_STS4_PGOOD_LDO9	BIT(4)
#define TPS65912_INT_STS4_PGOOD_LDO10	BIT(5)

/* GPIO 1 and 2 Register field definitions */
#define GPIO_SLEEP_MASK			0x80
#define GPIO_SLEEP_SHIFT		7
#define GPIO_DEB_MASK			0x10
#define GPIO_DEB_SHIFT			4
#define GPIO_CFG_MASK			0x04
#define GPIO_CFG_SHIFT			2
#define GPIO_STS_MASK			0x02
#define GPIO_STS_SHIFT			1
#define GPIO_SET_MASK			0x01
#define GPIO_SET_SHIFT			0

/* GPIO 3 Register field definitions */
#define GPIO3_SLEEP_MASK		0x80
#define GPIO3_SLEEP_SHIFT		7
#define GPIO3_SEL_MASK			0x40
#define GPIO3_SEL_SHIFT			6
#define GPIO3_ODEN_MASK			0x20
#define GPIO3_ODEN_SHIFT		5
#define GPIO3_DEB_MASK			0x10
#define GPIO3_DEB_SHIFT			4
#define GPIO3_PDEN_MASK			0x08
#define GPIO3_PDEN_SHIFT		3
#define GPIO3_CFG_MASK			0x04
#define GPIO3_CFG_SHIFT			2
#define GPIO3_STS_MASK			0x02
#define GPIO3_STS_SHIFT			1
#define GPIO3_SET_MASK			0x01
#define GPIO3_SET_SHIFT			0

/* GPIO 4 Register field definitions */
#define GPIO4_SLEEP_MASK		0x80
#define GPIO4_SLEEP_SHIFT		7
#define GPIO4_SEL_MASK			0x40
#define GPIO4_SEL_SHIFT			6
#define GPIO4_ODEN_MASK			0x20
#define GPIO4_ODEN_SHIFT		5
#define GPIO4_DEB_MASK			0x10
#define GPIO4_DEB_SHIFT			4
#define GPIO4_PDEN_MASK			0x08
#define GPIO4_PDEN_SHIFT		3
#define GPIO4_CFG_MASK			0x04
#define GPIO4_CFG_SHIFT			2
#define GPIO4_STS_MASK			0x02
#define GPIO4_STS_SHIFT			1
#define GPIO4_SET_MASK			0x01
#define GPIO4_SET_SHIFT			0

/* Register THERM  (0x80) register.RegisterDescription */
#define THERM_THERM_HD_MASK		0x20
#define THERM_THERM_HD_SHIFT		5
#define THERM_THERM_TS_MASK		0x10
#define THERM_THERM_TS_SHIFT		4
#define THERM_THERM_HDSEL_MASK		0x0C
#define THERM_THERM_HDSEL_SHIFT		2
#define THERM_RSVD1_MASK		0x02
#define THERM_RSVD1_SHIFT		1
#define THERM_THERM_STATE_MASK		0x01
#define THERM_THERM_STATE_SHIFT		0

/* Register DCDCCTRL1 register.RegisterDescription */
#define DCDCCTRL_VCON_ENABLE_MASK	0x80
#define DCDCCTRL_VCON_ENABLE_SHIFT	7
#define DCDCCTRL_VCON_RANGE1_MASK	0x40
#define DCDCCTRL_VCON_RANGE1_SHIFT	6
#define DCDCCTRL_VCON_RANGE0_MASK	0x20
#define DCDCCTRL_VCON_RANGE0_SHIFT	5
#define DCDCCTRL_TSTEP2_MASK		0x10
#define DCDCCTRL_TSTEP2_SHIFT		4
#define DCDCCTRL_TSTEP1_MASK		0x08
#define DCDCCTRL_TSTEP1_SHIFT		3
#define DCDCCTRL_TSTEP0_MASK		0x04
#define DCDCCTRL_TSTEP0_SHIFT		2
#define DCDCCTRL_DCDC1_MODE_MASK	0x02
#define DCDCCTRL_DCDC1_MODE_SHIFT	1

/* Register DCDCCTRL2 and DCDCCTRL3 register.RegisterDescription */
#define DCDCCTRL_TSTEP2_MASK		0x10
#define DCDCCTRL_TSTEP2_SHIFT		4
#define DCDCCTRL_TSTEP1_MASK		0x08
#define DCDCCTRL_TSTEP1_SHIFT		3
#define DCDCCTRL_TSTEP0_MASK		0x04
#define DCDCCTRL_TSTEP0_SHIFT		2
#define DCDCCTRL_DCDC_MODE_MASK		0x02
#define DCDCCTRL_DCDC_MODE_SHIFT	1
#define DCDCCTRL_RSVD0_MASK		0x01
#define DCDCCTRL_RSVD0_SHIFT		0

/* Register DCDCCTRL4 register.RegisterDescription */
#define DCDCCTRL_RAMP_TIME_MASK		0x01
#define DCDCCTRL_RAMP_TIME_SHIFT	0

/* Register DCDCx_AVS */
#define DCDC_AVS_ENABLE_MASK		0x80
#define DCDC_AVS_ENABLE_SHIFT		7
#define DCDC_AVS_ECO_MASK		0x40
#define DCDC_AVS_ECO_SHIFT		6

/* Register DCDCx_LIMIT */
#define DCDC_LIMIT_RANGE_MASK		0xC0
#define DCDC_LIMIT_RANGE_SHIFT		6
#define DCDC_LIMIT_MAX_SEL_MASK		0x3F
#define DCDC_LIMIT_MAX_SEL_SHIFT	0

/* Define the TPS65912 IRQ numbers */
enum tps65912_irqs {
	/* INT_STS registers */
	TPS65912_IRQ_PWRHOLD_F,
	TPS65912_IRQ_VMON,
	TPS65912_IRQ_PWRON,
	TPS65912_IRQ_PWRON_LP,
	TPS65912_IRQ_PWRHOLD_R,
	TPS65912_IRQ_HOTDIE,
	TPS65912_IRQ_GPIO1_R,
	TPS65912_IRQ_GPIO1_F,
	/* INT_STS2 registers */
	TPS65912_IRQ_GPIO2_R,
	TPS65912_IRQ_GPIO2_F,
	TPS65912_IRQ_GPIO3_R,
	TPS65912_IRQ_GPIO3_F,
	TPS65912_IRQ_GPIO4_R,
	TPS65912_IRQ_GPIO4_F,
	TPS65912_IRQ_GPIO5_R,
	TPS65912_IRQ_GPIO5_F,
	/* INT_STS3 registers */
	TPS65912_IRQ_PGOOD_DCDC1,
	TPS65912_IRQ_PGOOD_DCDC2,
	TPS65912_IRQ_PGOOD_DCDC3,
	TPS65912_IRQ_PGOOD_DCDC4,
	TPS65912_IRQ_PGOOD_LDO1,
	TPS65912_IRQ_PGOOD_LDO2,
	TPS65912_IRQ_PGOOD_LDO3,
	TPS65912_IRQ_PGOOD_LDO4,
	/* INT_STS4 registers */
	TPS65912_IRQ_PGOOD_LDO5,
	TPS65912_IRQ_PGOOD_LDO6,
	TPS65912_IRQ_PGOOD_LDO7,
	TPS65912_IRQ_PGOOD_LDO8,
	TPS65912_IRQ_PGOOD_LDO9,
	TPS65912_IRQ_PGOOD_LDO10,
};

/*
 * struct tps65912 - state holder for the tps65912 driver
 *
 * Device data may be used to access the TPS65912 chip
 */
struct tps65912 {
	struct device *dev;
	struct regmap *regmap;

	/* IRQ Data */
	int irq;
	struct regmap_irq_chip_data *irq_data;
};

extern const struct regmap_config tps65912_regmap_config;

int tps65912_device_init(struct tps65912 *tps);
int tps65912_device_exit(struct tps65912 *tps);

#endif /*  __LINUX_MFD_TPS65912_H */
