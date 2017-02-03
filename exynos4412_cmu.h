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

#ifndef __EXYNOS_4412_CMU
#define __EXYNOS_4412_CMU

#include "exynos4412.h"

void exynos4412_set_clock(u16 apll, u16 mpll, u16 epll);//set armclock to 1.4GHz
void exynos4412_system_clock_init(void);

#endif /* __EXYNOS_4412_CMU */

