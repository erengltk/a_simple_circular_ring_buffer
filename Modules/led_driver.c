/*
 * led_driver.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Eren
 */
#include "stm32f0xx_hal.h"

void led_driver_init(uint32_t ledNum)
{
	ledNum=(int)ledNum;
	RCC->AHBENR|=(1<<19);
	GPIOC->MODER|=(1<<(ledNum+ledNum));
	GPIOC->MODER&=~(1<<(ledNum+ledNum+1));
	GPIOC->OSPEEDR|=(1<<(ledNum+ledNum));
	GPIOC->OSPEEDR|=(1<<(ledNum+ledNum+1));
	GPIOC->OTYPER&=~(1<<ledNum);
}
void led_driver_on(uint32_t ledNum)
{
	ledNum=(int)ledNum;
	GPIOC->ODR|=(1<<ledNum);
}
void led_driver_off(uint32_t ledNum)
{
	GPIOC->ODR&=~(1<<ledNum);
}
