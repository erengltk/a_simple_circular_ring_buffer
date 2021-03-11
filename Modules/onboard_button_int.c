/*
 * onboard_button_int.c
 *
 *  Created on: Feb 13, 2021
 *      Author: Eren
 */
#include "stm32f0xx_hal.h"
#include"led_driver.h"
void onboard_button_int_init(void)
{
	RCC->AHBENR|=(1<<17); //PORT A CLOCK ENABLED
	GPIOA->MODER&=~(1<<0);
	GPIOA->MODER&=~(1<<1);// PORT A 0 INPUT
	GPIOA->PUPDR&=~(1<<0);
	GPIOA->PUPDR&=~(1<<1);//NO PULL UP OR DOWN
	SYSCFG->EXTICR[0]&=~(1<<3);
	SYSCFG->EXTICR[0]&=~(1<<2);
	SYSCFG->EXTICR[0]&=~(1<<1);
	SYSCFG->EXTICR[0]&=~(1<<0);//EXTI 0 CLOCK ENABLED
	EXTI->IMR|=(1<<0); // ZERO PIN INTERRUPT PIN UNMASKED
	EXTI->RTSR|=(1<<0);// RISING EDGE SELECTED
	NVIC_SetPriority(EXTI0_1_IRQn,1); // NVIC_SetPriority(5,1);
	NVIC_EnableIRQ(EXTI0_1_IRQn);// EXTI0 ENABLED
}
void EXTI0_1_IRQHandler(void)
{
	if((EXTI->PR&EXTI_PR_PR0)==EXTI_PR_PR0)
	{
		EXTI->PR|=EXTI_PR_PR0;
		GPIOC->ODR^=GPIO_PIN_8;

	}
}
