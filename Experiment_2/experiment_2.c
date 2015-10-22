#include <msp430f5435.h>
#include "array.h"

unsigned short array[] = PI_J;

void set_DCO_freq(unsigned char);
void set_MCLK_XT2(unsigned char);

void main(){
	WDTCTL = WDTPW + WDTHOLD;                 // Hold WDT
	
	//set_DCO_freq(16);
	set_MCLK_XT2(16);

	
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
  
/*  P4SEL |= (1 << 7);
  P2SEL |= (1 << 0);		//Debug */
  
  unsigned short temp, x, y;
  unsigned short n = sizeof(array)/sizeof(short);
	
	while(1){
		for(x=0; x<n; x++){
			for(y=0; y<n-1; y++){
				if(array[y]>array[y+1]){
					temp = array[y+1];
					array[y+1] = array[y];
					array[y] = temp;
				}
			}
		}
	}
}



void set_DCO_freq(unsigned char x){
	UCSCTL3 |= SELREF_2;                      // Set DCO FLL reference = REFO
	UCSCTL4 |= SELA_2;                        // Set ACLK = REFO

	__bis_SR_register(SCG0);                  // Disable the FLL control loop
  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx
  
	UCSCTL4 &= ~SELS_7;												// Clear SMCLK default selection
	UCSCTL4 |= SELS__REFOCLK;									// Set SMCLK = REFO
	__delay_cycles(250000);
	
  switch(x){
  	case 2:
		  UCSCTL1 = DCORSEL_4;                      // Select DCO range 16MHz operation
		  UCSCTL2 = FLLD_1 + 60;                   // Set DCO Multiplier for 8MHz  break; // (N + 1) * FLLRef = Fdco // (244 + 1) * 32768 = 8MHz  // Set FLL Div = fDCOCLK/2
		  break;
		case 4:
			UCSCTL1 = DCORSEL_5;                      // Select DCO range 16MHz operation
		  UCSCTL2 = FLLD_1 + 121;
		  break;
		case 8:                  
		  UCSCTL1 = DCORSEL_5;                      // Select DCO range 16MHz operation
		  UCSCTL2 = FLLD_1 + 243; 
			break;
		case 12:
			UCSCTL1 = DCORSEL_5;                      // Select DCO range 16MHz operation
		  UCSCTL2 = FLLD_1 + 365;
		  break;
		case 16:
			UCSCTL1 = DCORSEL_5;                      // Select DCO range 16MHz operation
		  UCSCTL2 = FLLD_1 + 487;
		  break;
		default:
			break;
  }
  
  __bic_SR_register(SCG0);                  // Enable the FLL control loop

  // Worst-case settling time for the DCO when the DCO range bits have been
  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
  // UG for optimization.
  // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle
  __delay_cycles(250000);

  // Loop until XT1,XT2 & DCO fault flag is cleared
  do
  {
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);
                                            // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

	
	
	return;
}	




void set_MCLK_XT2(unsigned char x){
    // XIN and XOUT are configured as GPIOs. To enable XT1 and X2T, the PSEL bits
    // associated with the crystal pin must be set.
    
  P5SEL |= ((1 << 3) | (1 << 2));   				//High freq XT2 select
  UCSCTL3 |= SELREF_2;                      
	UCSCTL6 &= ~(XT2OFF);            					// Set  XT2 On
	UCSCTL4 |= SELA_2;                        // Set ACLK = REFO
	UCSCTL6 |= (XT2DRIVE_1);									//Max current, max freq (8-16 MHz)
	UCSCTL6 &= ~(XT2BYPASS);									//Bypass mode OFF
  UCSCTL4 &= ~SELS_7;												// Clear SMCLK default selection
	UCSCTL4 |= SELS__REFOCLK;									// Set SMCLK = REFO
	__delay_cycles(250000); 
    
     
    
  do {                                                                         
      UCSCTL7 &= ~XT2OFFG;                /* XT2 fault flag */  
  }while (UCSCTL7&XT2OFFG);               /* Test XT2 fault flag */   
  
  switch(x){
  	case 1:
			UCSCTL5 |= DIVM__32; 				//Divide XT2 freq/32 for MCLK (1 MHz)
			UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
			break;
		case 2:
			UCSCTL5 |= DIVM__16; 				//Divide XT2 freq/16 for MCLK (2 MHz)
			UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
			break;
		case 4:
			UCSCTL5 |= DIVM__8; 				//Divide XT2 freq/8 for MCLK (4 MHz)
			UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
			break;
		case 8:
			UCSCTL5 |= DIVM__4; 				//Divide XT2 freq/4 for MCLK (8 MHz)
			UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
			break;
		case 16:
			UCSCTL5 |= DIVM__2; 				//Divide XT2 freq/2 for MCLK (16 MHz)
			UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
			break;
		case 32:
			UCSCTL5 |= DIVM__1; 				//Divide XT2 freq/1 for MCLK (32 MHz)
			UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
			break;
		default:
			UCSCTL5 |= DIVM__32; 				//Divide XT2 freq/32 for MCLK (1 MHz)
			UCSCTL4 |= SELM__XT2CLK;			//Select XT2 source for MCLK
			break;
  }
	
	__delay_cycles(250000);
	do {
  	UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG); 
		//OFIFG oscillator flag interrupt is set and latched at POR
		//or when any oscillator flag is detected.
  	SFRIFG1 &= ~OFIFG;                      // Clear fault flags
	}while (SFRIFG1&OFIFG);
	
	return;

}










//
//void init_button_1(){
//	P1SEL &= ~(BUTTON1_PIN);  /* Sets pin 1.4 as I/O */	
//	P1DIR &= ~(BUTTON1_PIN);  /* Sets pin 1.4 as input */
//	P1REN |= BUTTON1_PIN;		  /* Enables pullup/pulldown on P1.4 */
//  P1OUT |= BUTTON1_PIN; 		/* Sets pullup resistor*/
//  P1IES |= BUTTON1_PIN;			/* Falling edge detection*/
//  P1IFG &= ~(BUTTON1_PIN);	/* Clears button 1 interrupt*/
//  
//  return;
//}
