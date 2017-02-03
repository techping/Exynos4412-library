/**
  ******************************************************************************
  * @file    exynos4412.h
  * @author  Techping Chan <techping.chan@gmail.com>
  * @version V1.0.0
  * @date    25-January-2017
  * @brief   Exynos4412 ARM Cortex-A9 based Quad CPU 
  * 	     Device Peripheral Access Layer Header File. 
  *
  ******************************************************************************
  */

#ifndef __EXYNOS_4412_H
#define __EXYNOS_4412_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/**
 * IO definitions
 *
 * define access restrictions to peripheral registers
 */

#ifdef __cplusplus
  #define     __I     volatile                /*!< defines 'read only' permissions      */
#else
  #define     __I     volatile const          /*!< defines 'read only' permissions      */
#endif
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */

/* exact-width signed integer types */
typedef	signed	     	char	int8_t;
typedef	signed	short	int	int16_t;
typedef	signed	     	int	int32_t;
typedef	signed	long	long	int64_t;

/* exact-width unsigned integer types */
typedef	unsigned	     	char	uint8_t;
typedef	unsigned	short	int	uint16_t;
typedef	unsigned	     	int	uint32_t;
typedef	unsigned	long	long	uint64_t;

typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */

/** 
  * @brief General Purpose Input/Output (GPIO) Control ****************************************************
  */

typedef struct
{
	__IO uint32_t CON;
	__IO uint32_t DAT;
	__IO uint32_t PUD;
	__IO uint32_t DRV;
	__IO uint32_t CONPDN;
	__IO uint32_t PUDPDN;
} GPIO_TypeDef;

#define GPIO_PART1_R_BASE	((uint32_t)0x11400000) /* GPIO Part 1 registers base address */
#define GPIO_PART2_R_BASE	((uint32_t)0x11000000) /* GPIO Part 2 registers base address */
#define GPIO_PART3_R_BASE	((uint32_t)0x03860000) /* GPIO Part 3 registers base address */
#define GPIO_PART4_R_BASE	((uint32_t)0x106E0000) /* GPIO Part 4 registers base address */

/* GPIO Part 1 */

#define GPA0			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0000))
#define GPA1			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0020))
#define GPB			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0040))
#define GPC0			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0060))
#define GPC1			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0080))
#define GPD0			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x00A0))
#define GPD1			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x00C0))
#define GPF0			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0180))
#define GPF1			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x01A0))
#define GPF2			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x01C0))
#define GPF3			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x01E0))
#define GPJ0			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0240))
#define GPJ1			((GPIO_TypeDef *) (GPIO_PART1_R_BASE + 0x0260))

/* GPIO Part 2 */

#define GPK0			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0040))
#define GPK1			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0060))
#define GPK2			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0080))
#define GPK3			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x00A0))
#define GPL0			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x00C0))
#define GPL1			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x00E0))
#define GPL2			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0100))
#define GPY0			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0120))
#define GPY1			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0140))
#define GPY2			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0160))
#define GPY3			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0180))
#define GPY4			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x01A0))
#define GPY5			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x01C0))
#define GPY6			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x01E0))
#define GPM0			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0260))
#define GPM1			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0280))
#define GPM2			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x02A0))
#define GPM3			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x02C0))
#define GPX0			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0C00))
#define GPX1			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0C20))
#define GPX2			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0C40))
#define GPX3			((GPIO_TypeDef *) (GPIO_PART2_R_BASE + 0x0C60))

/* GPIO Part 3 */

#define GPZ			((GPIO_TypeDef *) (GPIO_PART3_R_BASE + 0x0000))

/* GPIO Part 4 */

#define GPV0			((GPIO_TypeDef *) (GPIO_PART4_R_BASE + 0x0000))
#define GPV1			((GPIO_TypeDef *) (GPIO_PART4_R_BASE + 0x0020))
#define GPV2			((GPIO_TypeDef *) (GPIO_PART4_R_BASE + 0x0060))
#define GPV3			((GPIO_TypeDef *) (GPIO_PART4_R_BASE + 0x0080))
#define GPV4			((GPIO_TypeDef *) (GPIO_PART4_R_BASE + 0x00C0))

/** 
  * @brief Clock Management Unit (CMU) ****************************************************
  */

typedef struct
{
	uint8_t	RESERVED1[0x4200];
	__IO uint32_t	CLK_SRC_LEFTBUS;
	uint8_t	RESERVED2[0x1fc];
	__IO uint32_t	CLK_MUX_STAT_LEFTBUS;
	uint8_t	RESERVED3[0xfc];
	__IO uint32_t	CLK_DIV_LEFTBUS;
	uint8_t	RESERVED4[0xfc];
	__IO uint32_t	CLK_DIV_STAT_LEFTBUS;
	uint8_t	RESERVED5[0x1fc];
	__IO uint32_t	CLK_GATE_IP_LEFTBUS;
	uint8_t	RESERVED6[0x12c];
	__IO uint32_t	CLK_GATE_IP_IMAGE;
	uint8_t	RESERVED7[0xcc];
	__IO uint32_t	CLKOUT_CMU_LEFTBUS;
	__IO uint32_t	CLKOUT_CMU_LEFTBUS_DIV_STAT;
	uint8_t	RESERVED8[0x37f8];
	__IO uint32_t	CLK_SRC_RIGHTBUS;
	uint8_t	RESERVED9[0x1fc];
	__IO uint32_t	CLK_MUX_STAT_RIGHTBUS;
	uint8_t	RESERVED10[0xfc];
	__IO uint32_t	CLK_DIV_RIGHTBUS;
	uint8_t	RESERVED11[0xfc];
	__IO uint32_t	CLK_DIV_STAT_RIGHTBUS;
	uint8_t	RESERVED12[0x1fc];
	__IO uint32_t	CLK_GATE_IP_RIGHTBUS;
	uint8_t	RESERVED13[0x15c];
	__IO uint32_t	CLK_GATE_IP_PERIR;
	uint8_t	RESERVED14[0x9c];
	__IO uint32_t	CLKOUT_CMU_RIGHTBUS;
	__IO uint32_t	CLKOUT_CMU_RIGHTBUS_DIV_STAT;
	uint8_t	RESERVED15[0x3608];
	__IO uint32_t	EPLL_LOCK;
	uint8_t	RESERVED16[0xc];
	__IO uint32_t	VPLL_LOCK;
	uint8_t	RESERVED17[0xec];
	__IO uint32_t	EPLL_CON0;
	__IO uint32_t	EPLL_CON1;
	__IO uint32_t	EPLL_CON2;
	uint8_t	RESERVED18[0x4];
	__IO uint32_t	VPLL_CON0;
	__IO uint32_t	VPLL_CON1;
	__IO uint32_t	VPLL_CON2;
	uint8_t	RESERVED19[0xe4];
	__IO uint32_t	CLK_SRC_TOP0;
	__IO uint32_t	CLK_SRC_TOP1;
	uint8_t	RESERVED20[0x8];
	__IO uint32_t	CLK_SRC_CAM0;
	__IO uint32_t	CLK_SRC_TV;
	__IO uint32_t	CLK_SRC_MFC;
	__IO uint32_t	CLK_SRC_G3D;
	uint8_t	RESERVED21[0x4];
	__IO uint32_t	CLK_SRC_LCD;
	__IO uint32_t	CLK_SRC_ISP;
	__IO uint32_t	CLK_SRC_MAUDIO;
	__IO uint32_t	CLK_SRC_FSYS;
	uint8_t	RESERVED22[0xc];
	__IO uint32_t	CLK_SRC_PERIL0;
	__IO uint32_t	CLK_SRC_PERIL1;
	__IO uint32_t	CLK_SRC_CAM1;
	uint8_t	RESERVED23[0xc4];
	__IO uint32_t	CLK_SRC_MASK_CAM0;
	__IO uint32_t	CLK_SRC_MASK_TV;
	uint8_t	RESERVED24[0xc];
	__IO uint32_t	CLK_SRC_MASK_LCD;
	__IO uint32_t	CLK_SRC_MASK_ISP;
	__IO uint32_t	CLK_SRC_MASK_MAUDIO;
	__IO uint32_t	CLK_SRC_MASK_FSYS;
	uint8_t	RESERVED25[0xc];
	__IO uint32_t	CLK_SRC_MASK_PERIL0;
	__IO uint32_t	CLK_SRC_MASK_PERIL1;
	uint8_t	RESERVED26[0xb8];
	__IO uint32_t	CLK_MUX_STAT_TOP0;
	__IO uint32_t	CLK_MUX_STAT_TOP1;
	uint8_t	RESERVED27[0x10];
	__IO uint32_t	CLK_MUX_STAT_MFC;
	__IO uint32_t	CLK_MUX_STAT_G3D;
	uint8_t	RESERVED28[0x28];
	__IO uint32_t	CLK_MUX_STAT_CAM1;
	uint8_t	RESERVED29[0xb4];
	__IO uint32_t	CLK_DIV_TOP;
	uint8_t	RESERVED30[0xc];
	__IO uint32_t	CLK_DIV_CAM0;
	__IO uint32_t	CLK_DIV_TV;
	__IO uint32_t	CLK_DIV_MFC;
	__IO uint32_t	CLK_DIV_G3D;
	uint8_t	RESERVED31[0x4];
	__IO uint32_t	CLK_DIV_LCD;
	__IO uint32_t	CLK_DIV_ISP;
	__IO uint32_t	CLK_DIV_MAUDIO;
	__IO uint32_t	CLK_DIV_FSYS0;
	__IO uint32_t	CLK_DIV_FSYS1;
	__IO uint32_t	CLK_DIV_FSYS2;
	__IO uint32_t	CLK_DIV_FSYS3;
	__IO uint32_t	CLK_DIV_PERIL0;
	__IO uint32_t	CLK_DIV_PERIL1;
	__IO uint32_t	CLK_DIV_PERIL2;
	__IO uint32_t	CLK_DIV_PERIL3;
	__IO uint32_t	CLK_DIV_PERIL4;
	__IO uint32_t	CLK_DIV_PERIL5;
	__IO uint32_t	CLK_DIV_CAM1;
	uint8_t	RESERVED32[0x14];
	__IO uint32_t	CLKDIV2_RATIO;
	uint8_t	RESERVED33[0x8c];
	__IO uint32_t	CLK_DIV_STAT_TOP;
	uint8_t	RESERVED34[0xc];
	__IO uint32_t	CLK_DIV_STAT_CAM0;
	__IO uint32_t	CLK_DIV_STAT_TV;
	__IO uint32_t	CLK_DIV_STAT_MFC;
	__IO uint32_t	CLK_DIV_STAT_G3D;
	uint8_t	RESERVED35[0x4];
	__IO uint32_t	CLK_DIV_STAT_LCD;
	__IO uint32_t	CLK_DIV_STAT_ISP;
	__IO uint32_t	CLK_DIV_STAT_MAUDIO;
	__IO uint32_t	CLK_DIV_STAT_FSYS0;
	__IO uint32_t	CLK_DIV_STAT_FSYS1;
	__IO uint32_t	CLK_DIV_STAT_FSYS2;
	__IO uint32_t	CLK_DIV_STAT_FSYS3;
	__IO uint32_t	CLK_DIV_STAT_PERIL0;
	__IO uint32_t	CLK_DIV_STAT_PERIL1;
	__IO uint32_t	CLK_DIV_STAT_PERIL2;
	__IO uint32_t	CLK_DIV_STAT_PERIL3;
	__IO uint32_t	CLK_DIV_STAT_PERIL4;
	__IO uint32_t	CLK_DIV_STAT_PERIL5;
	__IO uint32_t	CLK_DIV_STAT_CAM1;
	uint8_t	RESERVED36[0x14];
	__IO uint32_t	CLKDIV2_STAT;
	uint8_t	RESERVED37[0xc0];
	__IO uint32_t	CLK_GATE_BUS_FSYS1;	
	uint8_t	RESERVED38[0x1d8];
	__IO uint32_t	CLK_GATE_IP_CAM;
	__IO uint32_t	CLK_GATE_IP_TV;
	__IO uint32_t	CLK_GATE_IP_MFC;
	__IO uint32_t	CLK_GATE_IP_G3D;
	uint8_t	RESERVED39[0x4];
	__IO uint32_t	CLK_GATE_IP_LCD;
	__IO uint32_t	CLK_GATE_IP_ISP;
	uint8_t	RESERVED40[0x4];
	__IO uint32_t	CLK_GATE_IP_FSYS;
	uint8_t	RESERVED41[0x8];
	__IO uint32_t	CLK_GATE_IP_GPS;
	__IO uint32_t	CLK_GATE_IP_PERIL;
	uint8_t	RESERVED42[0x1c];
	__IO uint32_t	CLK_GATE_BLOCK;
	uint8_t	RESERVED43[0x8c];
	__IO uint32_t	CLKOUT_CMU_TOP;
	__IO uint32_t	CLKOUT_CMU_TOP_DIV_STAT;
	uint8_t	RESERVED44[0x3600];
	__IO uint32_t	MPLL_LOCK;
	uint8_t	RESERVED45[0xfc];
	__IO uint32_t	MPLL_CON0;
	__IO uint32_t	MPLL_CON1;
	uint8_t	RESERVED46[0xf0];
	__IO uint32_t	CLK_SRC_DMC;
	uint8_t	RESERVED47[0xfc];
	__IO uint32_t	CLK_SRC_MASK_DMC;
	uint8_t	RESERVED48[0xfc];
	__IO uint32_t	CLK_MUX_STAT_DMC;
	uint8_t	RESERVED49[0xfc];
	__IO uint32_t	CLK_DIV_DMC0;
	__IO uint32_t	CLK_DIV_DMC1;
	uint8_t	RESERVED50[0xf8];
	__IO uint32_t	CLK_DIV_STAT_DMC0;
	__IO uint32_t	CLK_DIV_STAT_DMC1;
	uint8_t	RESERVED51[0xf8];
	__IO uint32_t	CLK_GATE_BUS_DMC0;
	__IO uint32_t	CLK_GATE_BUS_DMC1;
	uint8_t	RESERVED52[0x1f8];
	__IO uint32_t	CLK_GATE_IP_DMC0;
	__IO uint32_t	CLK_GATE_IP_DMC1;
	uint8_t	RESERVED53[0xf8];
	__IO uint32_t	CLKOUT_CMU_DMC;
	__IO uint32_t	CLKOUT_CMU_DMC_DIV_STAT;
	uint8_t	RESERVED54[0x5f8];
	__IO uint32_t	DCGIDX_MAP0;
	__IO uint32_t	DCGIDX_MAP1;
	__IO uint32_t	DCGIDX_MAP2;
	uint8_t	RESERVED55[0x14];
	__IO uint32_t	DCGPERF_MAP0;
	__IO uint32_t	DCGPERF_MAP1;
	uint8_t	RESERVED56[0x18];
	__IO uint32_t	DVCIDX_MAP;
	uint8_t	RESERVED57[0x1c];
	__IO uint32_t	FREQ_CPU;
	__IO uint32_t	FREQ_DPM;
	uint8_t	RESERVED58[0x18];
	__IO uint32_t	DVSEMCLK_EN;
	__IO uint32_t	MAXPERF;
	uint8_t	RESERVED59[0xc];
	__IO uint32_t	DMC_PAUSE_CTRL;
	__IO uint32_t	DDRPHY_LOCK_CTRL;
	__IO uint32_t	C2C_STATE;
	uint8_t	RESERVED60[0x2f60];
	__IO uint32_t	APLL_LOCK;
	uint8_t	RESERVED61[0xfc];
	__IO uint32_t	APLL_CON0;
	__IO uint32_t	APLL_CON1;
	uint8_t	RESERVED62[0xf8];
	__IO uint32_t	CLK_SRC_CPU;
	uint8_t	RESERVED63[0x1fc];
	__IO uint32_t	CLK_MUX_STAT_CPU;
	uint8_t	RESERVED64[0xfc];
	__IO uint32_t	CLK_DIV_CPU0;
	__IO uint32_t	CLK_DIV_CPU1;
	uint8_t	RESERVED65[0xf8];
	__IO uint32_t	CLK_DIV_STAT_CPU0;
	__IO uint32_t	CLK_DIV_STAT_CPU1;
	uint8_t	RESERVED66[0x2f8];
	__IO uint32_t	CLK_GATE_IP_CPU;
	uint8_t	RESERVED67[0xfc];
	__IO uint32_t	CLKOUT_CMU_CPU;
	__IO uint32_t	CLKOUT_CMU_CPU_DIV_STAT;
	uint8_t	RESERVED68[0x5f8];
	__IO uint32_t	ARMCLK_STOPCTRL;
	__IO uint32_t	ATCLK_STOPCTRL;
	uint8_t	RESERVED69[0x18];
	__IO uint32_t	PWR_CTRL;
	__IO uint32_t	PWR_CTRL2;
	uint8_t	RESERVED70[0x3d8];
	__IO uint32_t	L2_STATUS;
	uint8_t	RESERVED71[0xc];
	__IO uint32_t	CPU_STATUS;
	uint8_t	RESERVED72[0xc];
	__IO uint32_t	PTM_STATUS;
	uint8_t	RESERVED73[0x2edc];
	__IO uint32_t	CLK_DIV_ISP0;
	__IO uint32_t	CLK_DIV_ISP1;
	uint8_t	RESERVED74[0xf8];
	__IO uint32_t	CLK_DIV_STAT_ISP0;
	__IO uint32_t	CLK_DIV_STAT_ISP1;
	uint8_t	RESERVED75[0x3f8];
	__IO uint32_t	CLK_GATE_IP_ISP0;
	__IO uint32_t	CLK_GATE_IP_ISP1;
	uint8_t	RESERVED76[0x1f8];
	__IO uint32_t	CLKOUT_CMU_ISP;
	__IO uint32_t	CLKOUT_CMU_ISP_DIV_STAT;
	uint8_t	RESERVED77[0xf8];
	__IO uint32_t	CMU_ISP_SPARE0;
	__IO uint32_t	CMU_ISP_SPARE1;
	__IO uint32_t	CMU_ISP_SPARE2;
	__IO uint32_t	CMU_ISP_SPARE3;
} CMU_TypeDef;

#define CMU_R_BASE	((uint32_t)0x10030000) /* CMU registers base address */

#define CMU			((CMU_TypeDef *) CMU_R_BASE)

/** 
  * @brief Universal Asynchronous Receiver and Transmitter (UART) ****************************************************
  */

typedef struct
{
	__IO uint32_t ULCON;
	__IO uint32_t UCON;
	__IO uint32_t UFCON;
	__IO uint32_t UMCON;
	__IO uint32_t UTRSTAT;
	__IO uint32_t UERSTAT;
	__IO uint32_t UFSTAT;
	__IO uint32_t UMSTAT;
	__IO uint32_t UTXH;
	__IO uint32_t URXH;
	__IO uint32_t UBRDIV;
	__IO uint32_t UFRACVAL;
	__IO uint32_t UINTP;
	__IO uint32_t UINTSP;
	__IO uint32_t UINTM;
} UART_TypeDef;

#define UART0_R_BASE	((uint32_t)0x13800000) /* UART Ch0 registers base address */
#define UART1_R_BASE	((uint32_t)0x13810000) /* UART Ch1 registers base address */
#define UART2_R_BASE	((uint32_t)0x13820000) /* UART Ch2 registers base address */
#define UART3_R_BASE	((uint32_t)0x13830000) /* UART Ch3 registers base address */
#define UART4_R_BASE	((uint32_t)0x13840000) /* UART Ch4 registers base address */

#define UART0			((UART_TypeDef *) UART0_R_BASE)
#define UART1			((UART_TypeDef *) UART1_R_BASE)
#define UART2			((UART_TypeDef *) UART2_R_BASE)
#define UART3			((UART_TypeDef *) UART3_R_BASE)
#define UART4			((UART_TypeDef *) UART4_R_BASE)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __EXYNOS_4412_H */

/******************* (C) COPYRIGHT 2017 Techping Chan *****END OF FILE****/

