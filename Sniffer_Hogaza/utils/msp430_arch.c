
#include <msp430f5435a.h>

#include "msp430_arch.h"

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

    // XIN and XOUT are configured as GPIOs. To enable XT1 and X2T, the PSEL bits
    // associated with the crystal pin must be set.
    
  	P5SEL |= ((1 << 3) | (1 << 2));   //High freq XT2 select
	P7SEL |= ((1 << 1) | (1 << 0));	//Low freq XT1 select
	UCSCTL6 &= ~(XT1OFF + XT2OFF);            // Set XT1 & XT2 On
	UCSCTL6 |= XCAP_3;                        // Internal load cap XT1
	UCSCTL6 &= ~(XTS); 						//Low Freq XT1
	UCSCTL6 |= (XT2DRIVE_3);			//Max current, max freq (24-32 MHz)
	UCSCTL6 &= ~(XT2BYPASS);			//Bypass mode OFF
   
    
    do{
        UCSCTL7 &= ~XT1LFOFFG;                // Clear XT1 fault flag
    }while (UCSCTL7&XT1LFOFFG);               // Test XT1 fault flag
    
    do{                                                                         
        UCSCTL7 &= ~XT2OFFG;                /* XT2 fault flag */  
    }while (UCSCTL7&XT2OFFG);               /* Test XT2 fault flag */   
    
    UCSCTL5 |= DIVS__2; 				//Divide XT2 freq/1 for SMCLK (16 MHz)
  	UCSCTL5 |= DIVM__2; 				//Divide XT2 freq/2 for MCLK (16 MHz)
  
  	UCSCTL4 |= SELS__XT2CLK;			//Select XT2 source for SMCLK
  	
	do{
		UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG); 
 		//OFIFG oscillator flag interrupt is set and latched at POR
 		//or when any oscillator flag is detected.
                                            // Clear XT2,XT1,DCO fault flags
    	SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  	}while (SFRIFG1&OFIFG);
  	__delay_cycles(250000);
  	
  	UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
  	
	do{
		UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG); 
 	//OFIFG oscillator flag interrupt is set and latched at POR
 	//or when any oscillator flag is detected.
                                            // Clear XT2,XT1,DCO fault flags
    	SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  	}while (SFRIFG1&OFIFG);
  	__delay_cycles(250000);
  	
  }   
