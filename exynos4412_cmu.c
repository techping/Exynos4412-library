/**
  ******************************************************************************
  * @file    exynos4412_cmu.h
  * @author  Techping Chan <techping.chan@gmail.com>
  * @version V1.0.0
  * @date    25-January-2017
  * @brief   This file aim to contain all the functions prototypes for the CMU 
  *          firmware library.
  ******************************************************************************
  */

#include "exynos4412_cmu.h"

void exynos4412_set_clock(u16 apll, u16 mpll, u16 epll)
{

	CMU->CLK_SRC_CPU = 0;

/* [Page 7-140] : Set (270 cycles x PDIV) to PLL_LOCKTIME for the PLL maximum lock time. */

	CMU->APLL_LOCK = 270 * 3;

/* 
 * CORE2_RATIO = 0;
 * APLL_RATIO = 2;
 * PCLK_DBG_RATIO = 1;
 * ATB_RATIO = 6;
 * PERIPH_RATIO = 7;
 * COREM1_RATIO = 7;
 * COREM0_RATIO = 3;
 * CORE_RATIO = 0;
 */

	CMU->CLK_DIV_CPU0 = ((0 << 28) | (2 << 24) | (1 << 20) | (6 << 16) | (7 << 12) | (7 << 8) | (3 << 4) | 0);

/*
 * CORES_RATIO = 5;
 * HPM_RATIO = 0;
 * COPY_RATIO = 6;
 */

	CMU->CLK_DIV_CPU1 = ((5 << 8) |(0 << 4) | (6));

	CMU->APLL_CON1 = 0x00803800;

/* [Page 7-8] Set APLL and MPLL to 1400 MHz, require P = 3, M = 175, S = 0 */

	CMU->APLL_CON0 = (1 << 31 | 175 << 16 | 3 << 8 | 0);

	CMU->CLK_SRC_CPU = 0x01000001;//MUXMPLL = FOUTMPLL;MUXAPLL = MOUTAPLLFOUT

	
}

/* CLK_DIV_DMC0	*/
#define CORE_TIMERS_RATIO	0x1
#define COPY2_RATIO		0x3
#define DMCP_RATIO		0x1
#define DMCD_RATIO		0x1
#define DMC_RATIO		0x1
#define DPHY_RATIO		0x1
#define ACP_PCLK_RATIO		0x1
#define ACP_RATIO		0x3
#define CLK_DIV_DMC0_VAL	((CORE_TIMERS_RATIO << 28) \
				| (COPY2_RATIO << 24)   \
				| (DMCP_RATIO << 20)	\
				| (DMCD_RATIO << 16)	\
				| (DMC_RATIO << 12)	\
				| (DPHY_RATIO << 8)	\
				| (ACP_PCLK_RATIO << 4)	\
				| (ACP_RATIO))

/* CLK_DIV_DMC1	*/
#define DPM_RATIO	        0x1
#define DVSEM_RATIO	        0x1
#define PWI_RATIO	        0x1
#define CLK_DIV_DMC1_VAL	((DPM_RATIO << 24) \
				| (DVSEM_RATIO << 16) \
				| (PWI_RATIO << 8))

/* CLK_DIV_TOP	*/
#define ONENAND_RATIO	0x0
#define ACLK_133_RATIO	0x5
#define ACLK_160_RATIO	0x4
#define ACLK_100_RATIO	0x7
#define ACLK_200_RATIO	0x3
#define CLK_DIV_TOP_VAL	((ONENAND_RATIO << 16) \
			| (ACLK_133_RATIO << 12)	\
			| (ACLK_160_RATIO << 8)	\
			| (ACLK_100_RATIO << 4)	\
			| (ACLK_200_RATIO))

/* CLK_DIV_LEFRBUS	*/
#define GPL_RATIO	        0x1
#define GDL_RATIO	        0x3
#define CLK_DIV_LEFRBUS_VAL	((GPL_RATIO << 4) \
				| (GDL_RATIO))

/* CLK_DIV_RIGHTBUS	*/
#define GPR_RATIO	        0x1
#define GDR_RATIO	        0x3
#define CLK_DIV_RIGHTBUS_VAL	((GPR_RATIO << 4) \
				| (GDR_RATIO))

/* CLK_DIV_CPU0	*/
#define CORE2_RATIO		0x0
#define APLL_RATIO		0x2
#define PCLK_DBG_RATIO		0x1
#define ATB_RATIO		0x6
#define PERIPH_RATIO		0x7
#define COREM1_RATIO		0x7
#define COREM0_RATIO		0x3
#define CORE_RATIO			0x0
#define CLK_DIV_CPU0_VAL        ((CORE2_RATIO << 28)	\
								| (APLL_RATIO << 24)     \
                                | (PCLK_DBG_RATIO << 20)\
                                | (ATB_RATIO << 16)     \
                                | (PERIPH_RATIO <<12)   \
								| (COREM1_RATIO << 8)   \
                                | (COREM0_RATIO << 4)   \
                                | (CORE_RATIO))

/* CLK_DIV_CPU1	*/
#define CORES_RADIO		0x5
#define HPM_RATIO	        0x0
#define COPY_RATIO	        0x6
#define CLK_DIV_CPU1_VAL	((HPM_RATIO << 4) | (COPY_RATIO))


#define CONFIG_CLK_1400_800_200/////////////////

#if defined(CONFIG_CLK_800_330_165)
#define APLL_MDIV	0xC8
#define APLL_PDIV	0x6
#define APLL_SDIV	0x1

#define MPLL_MDIV       0x6E
#define MPLL_PDIV	0x4
#define MPLL_SDIV	0x1
#elif defined(CONFIG_CLK_1000_400_200)
#define APLL_MDIV	0x7D
#define APLL_PDIV	0x3
#define APLL_SDIV	0x0

#define MPLL_MDIV	0x64
#define MPLL_PDIV	0x3
#define MPLL_SDIV	0x0
#elif defined(CONFIG_CLK_1400_800_200)
#define APLL_MDIV	0xAF
#define APLL_PDIV	0x3
#define APLL_SDIV	0x0

#define MPLL_MDIV	0x64
#define MPLL_PDIV	0x3
#define MPLL_SDIV	0x0
#endif

/* APLL_CON1	*/
#define APLL_CON1_VAL	0x00803800;

/* MPLL_CON1	*/
#define MPLL_CON1_VAL   0x00803800;


#define EPLL_MDIV	0x40
#define EPLL_PDIV	0x2
#define EPLL_SDIV	0x3
//define EPLL_K		0x66010000
#define EPLL_CON1_VAL	0x66010000
#define EPLL_CON2_VAL	0x00000080


#define VPLL_MDIV	0x48
#define VPLL_PDIV	0x2
#define VPLL_SDIV	0x3

#define VPLL_CON1_VAL	0x66010000
#define VPLL_CON2_VAL	0x00000080

/* Set PLL	*/
#define set_pll(mdiv, pdiv, sdiv)	(1<<31 | mdiv<<16 | pdiv<<8 | sdiv)

#define APLL_CON0_VAL	set_pll(APLL_MDIV,APLL_PDIV,APLL_SDIV)
#define MPLL_CON0_VAL	set_pll(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)
#define EPLL_CON0_VAL	set_pll(EPLL_MDIV,EPLL_PDIV,EPLL_SDIV)
#define VPLL_CON0_VAL	set_pll(VPLL_MDIV,VPLL_PDIV,VPLL_SDIV)


void exynos4412_system_clock_init(void)
{

//CMU_CPU MUX / DIV
	CMU->CLK_SRC_CPU = 0;
	CMU->CLK_DIV_DMC0 = CLK_DIV_DMC0_VAL;
	CMU->CLK_DIV_DMC1 = CLK_DIV_DMC1_VAL;

//CMU_TOP MUX / DIV
	CMU->CLK_SRC_TOP0 = 0;
	CMU->CLK_SRC_TOP1 = 0;
	CMU->CLK_DIV_TOP = CLK_DIV_TOP_VAL;

//CMU_LEFTBUS MUX / DIV
	CMU->CLK_SRC_LEFTBUS = 0x10;
	CMU->CLK_DIV_LEFTBUS = CLK_DIV_LEFRBUS_VAL;

//CMU_RIGHTBUS MUX / DIV
	CMU->CLK_SRC_RIGHTBUS = 0x10;
	CMU->CLK_DIV_RIGHTBUS = CLK_DIV_RIGHTBUS_VAL;

//Set PLL locktime
	CMU->APLL_LOCK = 270*3;//0x000002F1;
	CMU->MPLL_LOCK = 270*3;//0x000002F1;
	CMU->EPLL_LOCK = 0x00002321;
	CMU->VPLL_LOCK = 0x00002321;

	CMU->CLK_DIV_CPU0 = CLK_DIV_CPU0_VAL;
	CMU->CLK_DIV_CPU1 = CLK_DIV_CPU1_VAL;

//Set APLL
	CMU->APLL_CON1 = APLL_CON1_VAL;
	CMU->APLL_CON0 = APLL_CON0_VAL;

//////////////////////////////////skip

//Set MPLL
	CMU->MPLL_CON1 = MPLL_CON1_VAL;
	CMU->MPLL_CON0 = MPLL_CON0_VAL;

//Set EPLL
	CMU->EPLL_CON2 = EPLL_CON2_VAL;
	CMU->EPLL_CON1 = EPLL_CON1_VAL;
	CMU->EPLL_CON0 = EPLL_CON0_VAL;

//Set VPLL
	CMU->VPLL_CON2 = VPLL_CON2_VAL;
	CMU->VPLL_CON1 = VPLL_CON1_VAL;
	CMU->VPLL_CON0 = VPLL_CON0_VAL;
	
/////////////
	CMU->CLK_SRC_CPU = 0x01000001;
	CMU->CLK_SRC_DMC = 0x00011000;
	CMU->CLK_SRC_TOP0 = 0x00000110;
	CMU->CLK_SRC_TOP1 = 0x01111000;//0x00011000;
	
}


