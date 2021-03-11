/*
 * button_driver.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Eren
 */
#include "stm32f0xx_hal.h"
enum button_state {pressed,notPressed};

void user_button_driver_init(void)
{
	RCC->AHBENR|=(1<<17);
	GPIOA->MODER&=~(1<<1);
	GPIOA->MODER&=~(1<<0);
	GPIOA->PUPDR&=~(1<<1);
	GPIOA->PUPDR&=~(1<<0);
}
enum button_state user_button_driver_get_state(void)
{
	if(GPIOA->IDR & (1<<0))
		return pressed;
	else return notPressed;
}
a=9;
