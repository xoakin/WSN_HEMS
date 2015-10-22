#include <msp430f5435.h>
#include "msp430_arch.h"
#include "cc2520ll.h"


void main(){
	msp430_init();
	_enable_interrupts();
	if (cc2520ll_init() == SUCCESS){
		LPM0;
	}
}

#pragma vector = PORT2_VECTOR
interrupt void port2_interrupt(void) {
	if (P2IFG & (1 << CC2520_INT_PIN)){
		cc2520ll_packetReceivedISR();
		P2IFG &= ~(1 << CC2520_INT_PIN);
	}
}