/*
 * uart.c
 *
 *  Created on: Mar 2, 2021
 *      Author: Eren
 */

#include "stm32f0xx_hal.h"
#include "uart.h"
#define BUFFER_SIZE 256;
USART_TypeDef UartHandle;

static void UART_Error_Handler(void);

void UART_Init()
{

}

