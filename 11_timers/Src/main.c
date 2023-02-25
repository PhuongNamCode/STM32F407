
#include <stdio.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

#define GPIODEN 			(1U<<3)
#define PIN15 				(1U<<15)
#define LED_PIN 			PIN15

uint32_t sensor_value;

int main(void){
      //1.Enable clock  to access
      //  RCC_AHB1EN_R |=  GPIOAEN;
        RCC->AHB1ENR |= GPIODEN;
        //2. Set PA5 to out put pin
        GPIOD->MODER |=  (1U<<30);

        GPIOD->MODER &=~(1U<<31);
      while(1){
    	  while(!(TIM2->SR & SR_UIF)){}
    	  /*Clear UIF*/
    	  TIM2->SR &= ~ SR_UIF;
    	GPIOD-> ODR ^= LED_PIN;
      }
}
