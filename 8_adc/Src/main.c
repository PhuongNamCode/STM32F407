
#include <stdio.h>
#include "stm32f4xx.h"
#include "adc.h"

#define GPIODEN 			(1U<<3)
#define PIN15 				(1U<<15)
#define LED_PIN 			PIN15

uint32_t sensor_value;

int main(void){



//      uart2_tx_init();
        pa1_adc_init();



      while(1){

    	  	  start_conversion();
    	  	  sensor_value = adc_read();

      }
}
