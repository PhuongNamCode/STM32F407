#define PERIPH_BASE         (0x40000000UL)
#define AHB1PERIPH_OFFSET   (0x00020C00UL)

#define AHB1PERIPH_BASE     (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOD_OFFSET  		(0x0000U)
#define GPIOD_BASE 			(AHB1PERIPH_OFFSET+GPIOA_OFFSET)
#define RCC_OFFSET          (0x3800UL)
#define RCC_BASE  			(PERIPH_BASE + RCC_OFFSET)
#define AHB1EN_OFFSET       (0x30UL)
#define RCC_AHB1EN_R		 (*(volatile unsigned int *)(RCC_BASE+AHB1EN_OFFSET))

#define MODE_R_OFFSET       (0x00UL)
#define GPIOD_MODE_R        (*(volatile unsigned int *)(GPIOA_BASE+MODE_R_OFFSET))

#define OD_R_OFFSET         (0x14UL)
#define GPIOD_OD_R 			(*(volatile unsigned int *)(GPIOA_BASE+OD_R_OFFSET))
#define GPIODEN 			(1U<<0)// 0b 0000 0000 0000 0001 Add bit 1 to position 0
#define PIN15 				(1U<<15)
#define LED_PIN 			PIN15

int main(void){
    
       //1.Enable clock  to access 
       RCC_AHB1EN_R |=  GPIODEN;
       //2. Set PA5 to out put pin
       GPIOD_MODE_R |=  (1U<<10);
       GPIOD_MODE_R  &=~(1U<<11);

      while(1){
        GPIOD_OD_R ^= LED_PIN;
        for (int i = 0; i < 100000; i++){}
          
      }
}


