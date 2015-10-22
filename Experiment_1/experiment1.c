/* This program sets all the pins in the MCU to outputs at low level for 
 * decreasing power consumption. Then enters in the selected LPM or runs at
 * default MCLK frequency = 1.048576 MHz*/
 
#include <msp430f5435.h>

void main(){
	WDTCTL = WDTPW + WDTHOLD;                 // Hold WDT
	
	P1OUT = 0x00;
  P2OUT = 0x00;
  P3OUT = 0x00;
  P4OUT = 0x00;
  P5OUT = 0x00;
  P6OUT = 0x00;
  P7OUT = 0x00;
  P8OUT = 0x00;
  P9OUT = 0x00;
  P10OUT = 0x00;
  P11OUT = 0x00;
  PJOUT = 0x00;

  P1DIR = 0xFF;
  P2DIR = 0xFF;
  P3DIR = 0xFF;
  P4DIR = 0xFF;
  P5DIR = 0xFF;
  P6DIR = 0xFF;
  P7DIR = 0xFF;
  P8DIR = 0xFF;
  P9DIR = 0xFF;
  P10DIR = 0xFF;
  P11DIR = 0xFF;
  PJDIR = 0xFF;
	while(1){
		/* Uncomment the LPMx to be tested. Leave all commented for working at 
		 * default CPU frequency = 1.048576 MHz*/
		LPM0;
		//LPM1;
		//LPM2;
		//LPM3;
		//LPM4;
		__no_operation();
	}
}