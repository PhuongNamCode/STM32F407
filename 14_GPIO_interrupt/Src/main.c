
#include <stdio.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

#define GPIODEN 			(1U<<3)
#define PIN15 				(1U<<15)
#define LED_PIN 			PIN15

static void exti_callback();

int main(void){
  //1.Enable clock  to access
  //  RCC_AHB1EN_R |=  GPIOAEN;
  RCC->AHB1ENR |= GPIODEN;
  //2. Set PA5 to out put pin
  GPIOD->MODER |=  (1U<<30);

  GPIOD->MODER &=~(1U<<31);
	pc13_exti_init();
	while(1){

	}
}

static void exti_callback(void){
  printf ("BTN pressed\n");
  GPIOD->ODR ^= LED_PIN;
}

void EXTI15_10_IRQHandler(void){
  if((EXTI->PR & LINE13)!=0){
    // Clear flag
    EXTI->PR |= LINE13;
    // Do someting ....
    exti_callback();
  }
}
