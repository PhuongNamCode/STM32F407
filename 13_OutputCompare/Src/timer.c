/*
 * timer.c
 *
 *  Created on: Feb 21, 2023
 *      Author: Windows
 */

#include "stm32f4xx.h"

#define TIMER2EN        (1U<<0)
#define CR1_CEN         (1U<<0)
void timer2_1hz_init(void)
{
    /*Enable clock access*/
    RCC->APB1ENR |= TIMER2EN;
    /*Set prescaler value*/
    TIM2->PSC = 1600-1;
    /* Set the auto - load*/ 
    TIM2->ARR = 10000-1; // 16 000 000 : 1600 = 10 000
    /*Clear counter*/
    TIM2->CNT = 0;
    /*Enable timer */
    TIM2->CR1 = CR1_CEN;
}

void timer2_output_compare(void)
{
    /*Enable clock access*/
    RCC->APB1ENR |= TIMER2EN;
    /*Set prescaler value*/
    TIM2->PSC = 1600-1;
    /* Set the auto - load*/
    TIM2->ARR = 10000-1; // 16 000 000 : 1600 = 10 000
    /*Set output compare toggle mode*/
    // Enable tim2 ch1 in compare mode


    /*Clear counter*/
    TIM2->CNT = 0;
    /*Enable timer */
    TIM2->CR1 = CR1_CEN;
}
