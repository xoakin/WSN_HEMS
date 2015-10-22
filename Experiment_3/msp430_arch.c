
#include <msp430f5435.h>

#include "msp430_arch.h"

typedef void (* pt_func)(void);
static pt_func port1_vector[8] = {0,0,0,0,0,0,0,0};
static pt_func port2_vector[8] = {0,0,0,0,0,0,0,0};

/*---------------------------------------------------------------------------*/
/**
 * \brief	Turns on XT2 clock, set it to high frquency (32 MHZ) and sources
 * 			MCLK and SMCLK from it with no dividers.
 * 			Turns on LFXT1 clock, set it to high frequency sourced from 32 Khz
 * 			crystal and source ACLK from it with no dividers.
 */
void
msp430_init(void){
	
	WDTCTL = WDTPW + WDTHOLD; 		// Stop the watchdog

	// Every port not in use must me set as output to decrease 
	// overall current consumption (SLAU208G).
	// We first set every port as output and then each 
	// msp430 module configure the ports it will use.
	P1DIR = 0xFF;
	P2DIR = 0xFF;
	P3DIR = 0xFF;
	P4DIR = 0xFF;
	P5DIR = 0xFF;
	P6DIR = 0xFF;
	P7DIR = 0xFF;
	P8DIR = 0xFF;
	
	P1OUT = 0x00;
	P2OUT = 0x00;
	P3OUT = 0x00;
	P4OUT = 0x00;
	P5OUT = 0x00;
	P6OUT = 0x00;
	P7OUT = 0x00;
	P8OUT = 0x00;
	

    // XIN and XOUT are configured as GPIOs. To enable XT1 and X2T, the PSEL bits
    // associated with the crystal pin must be set.
  	P5SEL |= ((1 << 3) | (1 << 2));   //High freq XT2 select
	P7SEL |= ((1 << 1) | (1 << 0));	//Low freq XT1 select
	UCSCTL6 &= ~(XT1OFF + XT2OFF);          // Set XT1 & XT2 On
	UCSCTL6 |= XCAP_3;                      // Internal load cap XT1
	UCSCTL6 &= ~(XTS); 						// Low Freq XT1
	UCSCTL6 &= ~(XT1DRIVE1 | XT1DRIVE0);	// Lowest current consumption. Freq (4-8 MHz)
	
#if CPU_FREQ_16 || CPU_FREQ_8
	UCSCTL6 |= (XT2DRIVE1 | XT2DRIVE0);		// Max freq (8-16 MHz)
#endif
#if CPU_FREQ_4
	UCSCTL6 &= ~(XT2DRIVE1 | XT2DRIVE0);	// Lowest current consumption. Freq (4-8 MHz)
#endif
	UCSCTL6 &= ~(XT2BYPASS);				// Bypass mode OFF
   
    do{
        UCSCTL7 &= ~XT1LFOFFG;              // Clear XT1 fault flag
    }while (UCSCTL7&XT1LFOFFG);             // Test XT1 fault flag
    
    do {                                                                         
        UCSCTL7 &= ~XT2OFFG;                /* XT2 fault flag */  
    }while (UCSCTL7&XT2OFFG);               /* Test XT2 fault flag */   
    
#if CPU_FREQ_16
    UCSCTL5 |= DIVS__1; 				//Do not divide XT2 freq for SMCLK (16 MHz)
  	UCSCTL5 |= DIVM__1; 				//Do not divide XT2 freq for MCLK (16 MHz)
#endif
#if CPU_FREQ_8
    UCSCTL5 |= DIVS__2; 				//Divide XT2 freq/2 for SMCLK (8 MHz)
  	UCSCTL5 |= DIVM__2; 				//Divide XT2 freq/2 for MCLK (8 MHz)
#endif
#if CPU_FREQ_4
    UCSCTL5 |= DIVS__4; 				//Divide XT2 freq/4 for SMCLK (4 MHz)
  	UCSCTL5 |= DIVM__4; 				//Divide XT2 freq/4 for MCLK (4 MHz)
#endif

  	UCSCTL4 |= SELS__XT2CLK;			//Select XT2 source for SMCLK
  	
  	 do {
    	UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG); 
 		//OFIFG oscillator flag interrupt is set and latched at POR
 		//or when any oscillator flag is detected.
    	SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  	}while (SFRIFG1&OFIFG);
  	__delay_cycles(250000);
  	
  	UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
  	
  	 do {
    	UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG); 
 		//OFIFG oscillator flag interrupt is set and latched at POR
 		//or when any oscillator flag is detected.
    	SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  	}while (SFRIFG1&OFIFG);
  	__delay_cycles(250000);
}
   
void register_port1IntHandler(int i, void (*f)(void)) {
	port1_vector[i] = f;
}

void register_port2IntHandler(int i, void (*f)(void)) {
	port2_vector[i] = f;
}


#pragma vector = PORT2_VECTOR
interrupt void port2_interrupt(void) {
	int i;
	
	LPM3_EXIT;
	for (i = 0; i < 8; i++) {
		if (port2_vector[i] != 0 && (P2IFG & (1 << i)) && (P2IE & (1 << i))) {
			port2_vector[i]();
		}
	}
	P2IFG = 0x00; // clear flags
}
