#include "stm32f4xx.h"
#include "uart.h"

#define GPIODEN 			(1U<<3)
#define PIN15 				(1U<<15)
#define LED_PIN 			PIN15

char key;

int main(void){

       //1.Enable clock  to access
      //  RCC_AHB1EN_R |=  GPIOAEN;
      RCC->AHB1ENR |= GPIODEN;
       //2. Set PA5 to out put pin
      GPIOD->MODER |=  (1U<<30);

      GPIOD->MODER &=~(1U<<31);

      uart2_rxtx_init();

      while(1){
        
    	  key = uart2_read();
    	  if ( key == 1){
    		  GPIOD->ODR |= LED_PIN;
    	  }
    	  else
    		  GPIOD->ODR &= ~LED_PIN;

      }
}

