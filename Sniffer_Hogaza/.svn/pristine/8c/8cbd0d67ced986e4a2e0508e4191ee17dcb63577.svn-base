#include <msp430f5435a.h>

#include "leds.h"
//#include "hal_mcu.h"

void leds_init(void)
{
   	P6DIR |= (1 << 5)|(1 << 6)|(1 << 7);             // Set P6.5,6,7 to output direction
 	P6OUT &= ~((1 << 5)|(1 << 6)|(1 << 7));			// LEDs set OFF
}
void leds_on(void)
{
 	P6OUT |= (1 << 5)|(1 << 6)|(1 << 7);			
}
void leds_off(void)
{ 
 	P6OUT &= ~((1 << 5)|(1 << 6)|(1 << 7));			
}
void led_red(uint8_t i)
{
	if (i==1){ P6OUT |= (1 << 5);	}
	else if (i==0) { P6OUT &= ~(1 << 5);	}	
}
void led_yellow(uint8_t i)
{
	if (i==1){ P6OUT |= (1 << 6);	}
	else if (i==0) { P6OUT &= ~(1 << 6);	}	
}
void led_green(uint8_t i)
{
	if (i==1){ P6OUT |= (1 << 7);	}
	else if (i==0) { P6OUT &= ~(1 << 7);	}	
}
void leds_blink(uint8_t i)
{
	int n;
	
	if (i==0){
		for(;;){  
          	P6OUT ^= ((1 << 5)|(1 << 6)|(1 << 7));
    	  	halMcuWaitMs(400);
        }
	}else if (i > 0){
		for(n=0;n<i;n++){  
          	P6OUT ^= ((1 << 5)|(1 << 6)|(1 << 7));
    	  	halMcuWaitMs(400);
        }
	}
}
