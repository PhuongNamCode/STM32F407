/*
 * systick.c
 *
 *  Created on: Feb 21, 2023
 *      Author: Windows
 */

#include "stm32f4xx.h" 

#define SYSTICK_LOAD_VAL   16000 // 16000 CYCLES PER MS
#define CTRL_ENABLE         (1U<<0)
#define CTRL_CLKSRC         (1U<<2)
#define CTRL_COUNTFLAG      (1U<<16)

#define GPIODEN 			(1U<<3)
#define PIN15 				(1U<<15)
#define LED_PIN 			PIN15

void systickDelayMs(int delay )
{
    /*Configure systick*/
    /*Reload with the number of clocks per ms */
        SysTick->LOAD = SYSTICK_LOAD_VAL;
    /* Clear systick current value register */
        SysTick->VAL = 0;
    /* Enable systick and select internal clk src*/
        SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;
        for (int i = 0; i < delay ; i++){
            /*Wait until the COUNTFLAG is set*/
            while((SysTick->CTRL & CTRL_COUNTFLAG)==0){}
        };
        SysTick-> CTRL = 0;

}
