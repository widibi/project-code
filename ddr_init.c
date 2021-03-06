/*
 * Copyright 2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Author York Sun <york.sun@nxp.com>
 */

#include <platform_def.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <debug.h>
#include <errno.h>
#include <string.h>
#include <io.h>
#include <ddr.h>
#include <utils.h>
#include <utils_def.h>
#include <errata.h>

#ifdef CONFIG_STATIC_DDR
const struct ddr_cfg_regs static_1600 = {
    .cs[0].bnds = 0x7F,
    .cs[1].bnds = 0x008000BF,
    .cs[0].config = 0x80010412,
    .cs[1].config = 0x0202,
    .cs[2].bnds = 0x00C000FF,
    .cs[3].bnds = 0x0100013F,
    .cs[2].config = 0x0202,
    .cs[3].config = 0x0202,
    .cs[0].config_2 = 0x00,
    .cs[1].config_2 = 0x00,
    .cs[2].config_2 =  0x00,
    .cs[3].config_2 =  0x00,
    .sdram_cfg[0] = 0xC52C0000,
    .sdram_cfg[1] = 0x00401810,//0x00401810//0x00401010
    .timing_cfg[0] = 0x80550018,
    .timing_cfg[1] = 0xCCC60C42,
    .timing_cfg[2] = 0x0048D11C,
    .timing_cfg[3] = 0x01111000,
    .timing_cfg[4] = 0x01,
    .timing_cfg[5] = 0x04401400,
    .timing_cfg[7] = 0x23300000,
    .timing_cfg[8] = 0x03116600,
    .sdram_mode[0] = 0x04030214,
    .sdram_mode[1] = 0x00,
    .sdram_mode[2] = 0x00,
    .sdram_mode[3] = 0x00,
    .sdram_mode[4] = 0x00,
    .sdram_mode[5] = 0x00,
    .sdram_mode[6] = 0x00,
    .sdram_mode[7] = 0x00,
    .sdram_mode[8] = 0x0400,
    .sdram_mode[9] = 0x04800000,
    .sdram_mode[10] = 0x00,
    .sdram_mode[11] = 0x00,
    .sdram_mode[12] = 0x00,
    .sdram_mode[13] = 0x00,
    .sdram_mode[14] = 0x00,
    .sdram_mode[15] = 0x00,
	.dq_map[0] = 0x00,
	.dq_map[1] = 0x00,
	.dq_map[2] = 0x00,
	.dq_map[3] = 0x00,
    .md_cntl = 0x00,
    .interval = 0x18600618,
    .data_init = 0xDEADBEEF,
    .clk_cntl = 0x04000000,
    .init_addr = 0x00,
    .init_ext_addr = 0x00,
    .zq_cntl = 0x8A090705,
    .wrlvl_cntl[0] = 0x86750606,
    .wrlvl_cntl[1] = 0x06070805,
    .wrlvl_cntl[2] = 0x05050500,
    //.deskew_cntl = 0x00,
    .cdr[0] = 0x80040000,
    .cdr[1] = 0xA180,
    .debug[1] = 0x10,
    .debug[28] = 0x01080F37
};

const struct ddr_cfg_regs static_1300 = {
    .cs[0].bnds = 0x7F,
    .cs[1].bnds = 0x008000BF,
    .cs[0].config = 0x80010412,
    .cs[1].config = 0x0202,
    .cs[2].bnds = 0x00C000FF,
    .cs[3].bnds = 0x0100013F,
    .cs[2].config = 0x0202,
    .cs[3].config = 0x0202,
    .cs[0].config_2 = 0x00,
    .cs[1].config_2 = 0x00,
    .cs[2].config_2 =  0x00,
    .cs[3].config_2 =  0x00,
    .sdram_cfg[0] = 0xC52C0000,
    .sdram_cfg[1] = 0x00401010,//0x00401810
    .timing_cfg[0] = 0x80440018,
    .timing_cfg[1] = 0xA7A2CA42,
    .timing_cfg[2] = 0x0048B11C,
    .timing_cfg[3] = 0x010D1000,
    .timing_cfg[4] = 0x01,
    .timing_cfg[5] = 0x02401400,
    .timing_cfg[7] = 0x12200000,
    .timing_cfg[8] = 0x01115500,
    .sdram_mode[0] = 0x01010004,
    .sdram_mode[1] = 0x00,
    .sdram_mode[2] = 0x00,
    .sdram_mode[3] = 0x00,
    .sdram_mode[4] = 0x00,
    .sdram_mode[5] = 0x00,
    .sdram_mode[6] = 0x00,
    .sdram_mode[7] = 0x00,
    .sdram_mode[8] = 0x0400,
    .sdram_mode[9] = 0x00800000,
    .sdram_mode[10] = 0x00,
    .sdram_mode[11] = 0x00,
    .sdram_mode[12] = 0x00,
    .sdram_mode[13] = 0x00,
    .sdram_mode[14] = 0x00,
    .sdram_mode[15] = 0x00,
	.dq_map[0] = 0x4303B040,
	.dq_map[1] = 0xB90D8000,
	.dq_map[2] = 0x00,
	.dq_map[3] = 0x00,
	// .dq_map[0] = 0x4303B040,
	// .dq_map[1] = 0xB90D8000,
	// .dq_map[2] = 0x00,
	// .dq_map[3] = 0x00,
    .md_cntl = 0x00,
    .interval = 0x13CE04F3,
    .data_init = 0xDEADBEEF,
    .clk_cntl = 0x02800000,
    .init_addr = 0x00,
    .init_ext_addr = 0x00,
    .zq_cntl = 0x8A090705,
    .wrlvl_cntl[0] = 0x86750606,
    .wrlvl_cntl[1] = 0x06060605,
    .wrlvl_cntl[2] = 0x05050500,
    //.deskew_cntl = 0x00,
    .cdr[0] = 0x80040000,
    .cdr[1] = 0xA181,
    //.debug[1] = 0x10,
    .debug[28] = 0x01080F37
};

long long board_static_ddr(struct ddr_info *priv)
{
//	memcpy(&priv->ddr_reg, &static_1300, sizeof(static_1300));
 	memcpy(&priv->ddr_reg, &static_1600, sizeof(static_1600));

	return 0x80000000;
}

#else
static const struct rc_timing rcz[] = {
	{1600, 12, 7},
	{}
};

static const struct board_timing ram[] = {
	{0x1f, rcz, 0x00020100, 0},
};

int ddr_board_options(struct ddr_info *priv)
{
	int ret;
	struct memctl_opt *popts = &priv->opt;

	ret = cal_board_params(priv, ram, ARRAY_SIZE(ram));
	if (ret)
		return ret;

	popts->cpo_sample = 0x46;
	popts->ddr_cdr1 = DDR_CDR1_DHC_EN |
			  DDR_CDR1_ODT(DDR_CDR_ODT_80ohm);
	popts->ddr_cdr2 = DDR_CDR2_ODT(DDR_CDR_ODT_80ohm) |
			  DDR_CDR2_VREF_OVRD(70);	/* Vref = 70% */

	return 0;
}

/* DDR model number: MT40A512M8HX-093E */
struct dimm_params ddr_raw_timing = {
	.n_ranks = 1,
	.rank_density = 2147483648u,
	.capacity = 2147483648u,
	.primary_sdram_width = 32,
	.n_row_addr = 15,
	.n_col_addr = 10,
	.bank_group_bits = 2,
	.burst_lengths_bitmask = 0x0c,
	.tckmin_x_ps = 938,
	.tckmax_ps = 1500,
	.caslat_x = 0x000DFA00,
	.taa_ps = 13500,
	.trcd_ps = 13500,
	.trp_ps = 13500,
	.tras_ps = 33000,
	.trc_ps = 46500,
	.twr_ps = 15000,
	.trfc1_ps = 260000,
	.trfc2_ps = 160000,
	.trfc4_ps = 110000,
	.tfaw_ps = 21000,
	.trrds_ps = 3700,
	.trrdl_ps = 5300,
	.tccdl_ps = 5355,
	.refresh_rate_ps = 7800000,
	.rc = 0x1f,
};

int ddr_get_ddr_params(struct dimm_params *pdimm,
			    struct ddr_conf *conf)
{
	static const char dimm_model[] = "Fixed DDR on board";

	conf->dimm_in_use[0] = 1;
	memcpy(pdimm, &ddr_raw_timing, sizeof(struct dimm_params));
	memcpy(pdimm->mpart, dimm_model, sizeof(dimm_model) - 1);

	return 1;
}
#endif

long long _init_ddr(void)
{
	struct ddr_info info;
	struct sysinfo sys;
	long long dram_size;

	zeromem(&sys, sizeof(sys));
	get_clocks(&sys);
	debug("platform clock %lu\n", sys.freq_platform);
	debug("DDR PLL1 %lu\n", sys.freq_ddr_pll0);
	debug("DDR PLL2 %lu\n", sys.freq_ddr_pll1);

	zeromem(&info, sizeof(struct ddr_info));
	info.num_ctlrs = 1;
	info.dimm_on_ctlr = 1;
	info.clk = get_ddr_freq(&sys, 0);
	info.ddr[0] = (void *)NXP_DDR_ADDR;

	dram_size = dram_init(&info);

	if (dram_size < 0)
		ERROR("DDR init failed\n");

	erratum_a008850_post();

	return dram_size;
}
