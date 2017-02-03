/**
  ******************************************************************************
  * @file    exynos4412_uart.h
  * @author  Techping Chan <techping.chan@gmail.com>
  * @version V1.0.0
  * @date    25-January-2017
  * @brief   This file aim to contain all the functions prototypes for the UART 
  *          firmware library.
  ******************************************************************************
  */

#ifndef __EXYNOS_4412_UART
#define __EXYNOS_4412_UART

#include "exynos4412.h"

/*
 * PARITY_MODE
 */
#define NO_PARITY 0
#define ODD_PARITY 4
#define EVEN_PARITY 5
#define PARITY_FORCED_1 6
#define PARITY_FORCED_0 7

void exynos4412_uart_init(UART_TypeDef *UARTx, u32 uart_clock, u32 baudrate, u8 word_length, u8 parity_mode, u8 stop_bit_num);/* uart_clock:nMHz */
char exynos4412_uart_getc(UART_TypeDef *UARTx);
void exynos4412_uart_putc(UART_TypeDef *UARTx, char c);
void exynos4412_uart_puts(UART_TypeDef *UARTx, char* str);

void exynos4412_uart_printf(UART_TypeDef *UARTx, char *fmt, ...);

#endif /* __EXYNOS_4412_UART */

