#include <msp430f5435.h>
#include "msp430_arch.h"
#include "buttons.h"
#include "cc2520ll.h"

int i;

void main(){
	i = 0;
	uint16_t len;
	//uint8_t tx_buf[] = {'H','E','L','L','O'};//,'H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O','H','E','L','L','O',};
	uint8_t tx_buf[] = {0x41, 0x88, 0x00, 0x10, 0x20, 0xBB, 0xBB, 0xAA, 0xAA, 0xFF, 0xFF};
	msp430_init();
	buttons_init();
	len = sizeof(tx_buf)/sizeof(uint8_t);
	if (cc2520ll_init() == SUCCESS){
		
//		cc2520ll_receiveOff();
		
		__disable_interrupt();
		P1IE &= ~(1 << BUTTON1_PIN);
		while(!buttons_1pressed());
//		cc2520ll_receiveOn();
//		while(i == 1);
		cc2520ll_packetSend(tx_buf,len);
			while(1);
//		}
	}
	
	
	while(1){
		LPM0;
		__no_operation();
	}
}

#pragma vector = PORT1_VECTOR
interrupt void port1_interrupt(void) {
	if (P1IFG & (1 << BUTTON1_PIN)){
		P1IE &= ~(1 << BUTTON1_PIN);
		while(buttons_1pressed());
	 	i++;
	  P1IE |= (1 << BUTTON1_PIN);
		P1IFG = 0x00; // clear flags
	}
}
