/**
 * ddr_training_custom.h
 *
 * Copyright (c) 2009-2014, HiSilicon Technologies Co., Ltd.
 * All rights reserved.
 *
 * DDR training custom define.
 */

/* config DDRC, PHY, DDRT typte */
#define DDR_DDRC_V510_CONFIG
#define DDR_PHY_T28_CONFIG
#define DDR_DDRT_T28_CONFIG

/* config special item */
#define DDR_TRAINING_UART_DISABLE
#define DDR_VREF_TRAINING_CONFIG
#define DDR_MPR_TRAINING_CONFIG
#define DDR_VREF_WITHOUT_BDL_CONFIG

/* config DDRC, PHY, DDRT base address */
/* [CUSTOM] DDR DMC0 base register */
#define DDR_REG_BASE_DMC0		0x12118000
/* [CUSTOM] DDR DMC1 base register */
#define DDR_REG_BASE_DMC1		0x12119000
/* [CUSTOM] DDR PHY0 base register */
#define DDR_REG_BASE_PHY0		0x1211c000
/* [CUSTOM] DDR PHY1 base register */
#define DDR_REG_BASE_PHY1		0x1211e000
/* [CUSTOM] DDR DDRT base register */
#define DDR_REG_BASE_DDRT		0x12100000
/* [CUSTOM] DDR training item system control */
#define DDR_REG_BASE_SYSCTRL		0x12050000
#define DDR_REG_BASE_AXI		0x12110000

/* config offset address */
/* Assume sysctrl offset address for DDR training as follows,
if not please define. */
/* [CUSTOM] ddrt reversed data */
#define SYSCTRL_DDRT_PATTERN		0x94
/* [CUSTOM] PHY2 ddrt reversed data */
#define SYSCTRL_DDRT_PATTERN_SEC    0x130
/* [CUSTOM] ddr training item */
#define SYSCTRL_DDR_TRAINING_CFG	0x90
/* [CUSTOM] ddr training stat */
#define SYSCTRL_DDR_TRAINING_STAT	0x98

/* config other special */
/* [CUSTOM] DDR training start address. MEM_BASE_DDR*/
#define DDRT_CFG_BASE_ADDR		0x40000000
/* [CUSTOM] SRAM start address.
NOTE: Makefile will parse it, plase define it as Hex. eg: 0xFFFF0C00 */
#define DDR_TRAINING_RUN_STACK		0x04016000
