// SPDX-License-Identifier: (BSD-3-Clause OR GPL-2.0-only)
/* Copyright(c) 2015 - 2020 Intel Corporation */
#include <adf_accel_devices.h>
#include <adf_pf2vf_msg.h>
#include <adf_common_drv.h>
#include "adf_c62xvf_hw_data.h"

static struct adf_hw_device_class c62xiov_class = {
	.name = ADF_C62XVF_DEVICE_NAME,
	.type = DEV_C62XVF,
	.instances = 0
};

static u32 get_accel_mask(u32 fuse)
{
	return ADF_C62XIOV_ACCELERATORS_MASK;
}

static u32 get_ae_mask(u32 fuse)
{
	return ADF_C62XIOV_ACCELENGINES_MASK;
}

static u32 get_num_accels(struct adf_hw_device_data *self)
{
	return ADF_C62XIOV_MAX_ACCELERATORS;
}

static u32 get_num_aes(struct adf_hw_device_data *self)
{
	return ADF_C62XIOV_MAX_ACCELENGINES;
}

static u32 get_misc_bar_id(struct adf_hw_device_data *self)
{
	return ADF_C62XIOV_PMISC_BAR;
}

static u32 get_etr_bar_id(struct adf_hw_device_data *self)
{
	return ADF_C62XIOV_ETR_BAR;
}

static enum dev_sku_info get_sku(struct adf_hw_device_data *self)
{
	return DEV_SKU_VF;
}

static u32 get_pf2vf_offset(u32 i)
{
	return ADF_C62XIOV_PF2VF_OFFSET;
}

static u32 get_vintmsk_offset(u32 i)
{
	return ADF_C62XIOV_VINTMSK_OFFSET;
}

static int adf_vf_int_noop(struct adf_accel_dev *accel_dev)
{
	return 0;
}

static void adf_vf_void_noop(struct adf_accel_dev *accel_dev)
{
}

void adf_init_hw_data_c62xiov(struct adf_hw_device_data *hw_data)
{
	hw_data->dev_class = &c62xiov_class;
	hw_data->num_banks = ADF_C62XIOV_ETR_MAX_BANKS;
	hw_data->num_accel = ADF_C62XIOV_MAX_ACCELERATORS;
	hw_data->num_logical_accel = 1;
	hw_data->num_engines = ADF_C62XIOV_MAX_ACCELENGINES;
	hw_data->tx_rx_gap = ADF_C62XIOV_RX_RINGS_OFFSET;
	hw_data->tx_rings_mask = ADF_C62XIOV_TX_RINGS_MASK;
	hw_data->alloc_irq = adf_vf_isr_resource_alloc;
	hw_data->free_irq = adf_vf_isr_resource_free;
	hw_data->enable_error_correction = adf_vf_void_noop;
	hw_data->init_admin_comms = adf_vf_int_noop;
	hw_data->exit_admin_comms = adf_vf_void_noop;
	hw_data->send_admin_init = adf_vf2pf_init;
	hw_data->init_arb = adf_vf_int_noop;
	hw_data->exit_arb = adf_vf_void_noop;
	hw_data->disable_iov = adf_vf2pf_shutdown;
	hw_data->get_accel_mask = get_accel_mask;
	hw_data->get_ae_mask = get_ae_mask;
	hw_data->get_num_accels = get_num_accels;
	hw_data->get_num_aes = get_num_aes;
	hw_data->get_etr_bar_id = get_etr_bar_id;
	hw_data->get_misc_bar_id = get_misc_bar_id;
	hw_data->get_pf2vf_offset = get_pf2vf_offset;
	hw_data->get_vintmsk_offset = get_vintmsk_offset;
	hw_data->get_sku = get_sku;
	hw_data->enable_ints = adf_vf_void_noop;
	hw_data->enable_vf2pf_comms = adf_enable_vf2pf_comms;
	hw_data->min_iov_compat_ver = ADF_PFVF_COMPATIBILITY_VERSION;
	hw_data->dev_class->instances++;
	adf_devmgr_update_class_index(hw_data);
}

void adf_clean_hw_data_c62xiov(struct adf_hw_device_data *hw_data)
{
	hw_data->dev_class->instances--;
	adf_devmgr_update_class_index(hw_data);
}
