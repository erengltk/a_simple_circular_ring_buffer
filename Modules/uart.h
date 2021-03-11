/*
 * uart.h
 *
 *  Created on: Feb 18, 2021
 *      Author: Eren
 */

#ifndef MODULES_UART_H_
#define MODULES_UART_H_
void UART_Init();
void UART_send_byte(uint8_t data);
int32_t UART_read_byte();
void UART_send_byte_array(uint8_t* buffer, uint32_t size);
uint32_t UART_bytes_to_read(void);


#endif /* MODULES_UART_H_ */
