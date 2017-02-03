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

#include "exynos4412_uart.h"

void exynos4412_uart_init(UART_TypeDef *UARTx, u32 uart_clock, u32 baudrate, u8 word_length, u8 parity_mode, u8 stop_bit_num)
{
	u32 ulcon_temp, mantissa, fraction;
	float clock_temp;

/*
 * The sample based on Xunwei iTOP4412
 * CON2(UART3):GPS_TXD:GPA1_4;GPS_RXD:GPA1_5
 * CON3(UART2):UART_AUDIO_TXD:GPA1_1;UART_AUDIO_RXD:GPA1_0
 */
	switch ((u32)UARTx) {
	case ((u32)UART2):
		GPA1->CON &= ~(0xFF);
		GPA1->CON |= 0x22;
		break;
	case ((u32)UART3):
		GPA1->CON &= ~(0xFF << 16);
		GPA1->CON |= 0x22 << 16;
		break;
	default: break;
	}

/*
 * PWM_SEL = 0;
 * UART4_SEL = 6;
 * UART3_SEL = 6;
 * UART2_SEL = 6;
 * UART1_SEL = 6;
 * UART0_SEL = 6;
 */

	CMU->CLK_SRC_PERIL0 = ((6 << 16) | (6 << 12) | (6 << 8) | (6 << 4) | (6));

	CMU->CLK_DIV_PERIL0 = ((7 << 20) | (7 << 16) | (7 << 12) | (7 << 8) | (7 << 4) | (7));

	UARTx->UFCON = 0x111;

	
	switch (word_length) {
	case 5:
		ulcon_temp = 0;
		break;
	case 6:
		ulcon_temp = 1;
		break;
	case 7:
		ulcon_temp = 2;
		break;
	case 8:
		ulcon_temp = 3;
		break;
	default: break;
	}

	switch (stop_bit_num) {
	case 0:
		ulcon_temp &= ~(1 << 2);
		break;
	case 1:
		ulcon_temp |= (1 << 2);
		break;
	default: break;	
	}

	ulcon_temp |= parity_mode << 3;

	UARTx->ULCON = ulcon_temp;

	UARTx->UCON = 0x5;


/* UBRDIVn = (int)( UART clock / ( buad rate x 16) ) – 1 
 *	   = uart_clock * 1000000 / (baudrate * 16) - 1
 */
	
	clock_temp = uart_clock * 1000000 / (float)(baudrate * 16) - 1;
	mantissa = clock_temp;
	fraction = (clock_temp - mantissa) * 16; 
	UARTx->UBRDIV = mantissa;
	UARTx->UFRACVAL = fraction;
}

char exynos4412_uart_getc(UART_TypeDef *UARTx)
{
	while (!(UARTx->UTRSTAT & (1 << 0)));
	return UARTx->URXH;
}

void exynos4412_uart_putc(UART_TypeDef *UARTx, char c)
{
	while (!(UARTx->UTRSTAT & (1 << 2)));
	UARTx->UTXH = c; 
}

void exynos4412_uart_puts(UART_TypeDef *UARTx, char* str)
{
	int i = 0;
	while (str[i]) {
		while (!(UARTx->UTRSTAT & (1 << 2)));
		UARTx->UTXH = (char)str[i ++];
	}
}

