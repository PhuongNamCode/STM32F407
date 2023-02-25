#include "stm32f4xx.h"

#define GPIODEN 			(1U<<3)
#define PIN15 				(1U<<15)
#define LED_PIN 			PIN15


int main(void){

       //1.Enable clock  to access
      //  RCC_AHB1EN_R |=  GPIOAEN;
      RCC->AHB1ENR |= GPIODEN;
       //2. Set PA5 to out put pin
      GPIOD->MODER |=  (1U<<30);

      GPIOD->MODER &=~(1U<<31);

      while(1){
        
        GPIOD->BSRR = LED_PIN;
        for (int i = 0; i < 100000; i++){}
        GPIOD->BSRR = (1U<<31);
        for (int i = 0; i < 100000; i++){}
      }
}

