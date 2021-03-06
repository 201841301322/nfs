/******************************************************************************
*    Copyright (c) 2009-2012 by Hisi.
*    All rights reserved.
* ***
******************************************************************************/

#include <config.h>

#define readl(_a)        (*(volatile unsigned int *)(_a))
#define writel(_v, _a)   (*(volatile unsigned int *)(_a) = (_v))

#define HI_CHIP_ID _HI3531D_V100
extern void udelay(unsigned long usec);
/******************************************************************************/

static inline void delay(unsigned int cnt)
{
	while (cnt--)
		__asm__ __volatile__("nop");
}

/******************************************************************************/

long long get_chipid_reg(void)
{
	long long chipid = 0;

	chipid = HI_CHIP_ID;

	return chipid;
}

/******************************************************************************/

void reset_cpu(unsigned long addr)
{
	while (1) {
		/* Any value to this reg will reset the cpu */
		writel(0x12345678, (SYS_CTRL_REG_BASE + REG_SC_SYSRES));
		udelay(500);
	}
}
/******************************************************************************/
