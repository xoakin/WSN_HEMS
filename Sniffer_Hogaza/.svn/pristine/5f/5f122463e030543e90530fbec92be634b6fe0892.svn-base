#include <msp430f5418a.h>

#include "buttons.h"



/*---------------------------------------------------------------------------*/

/**
 * Initialize the buttons in the board 
 */ 
/*---------------------------------------------------------------------------*/

void
buttons_init(void)
{
	P1SEL &= ~(BUTTON1_PIN);  /* Set pins 1.4 as I/O */	
	P1DIR &= ~(BUTTON1_PIN);  /* Set pin 1.4 as input */
	P1REN |= (1 << 4);		  // Set pullup/pulldown on P1.4
    P1OUT |= (1 << 4); 
    
    P2SEL &= ~(BUTTON2_PIN);  /* Set pins 2.6 as I/O */	 
	P2DIR &= ~(BUTTON2_PIN);  /* Set pin 2.6 as input */
    P2REN |= (1 << 6);		  // Set pullup/pulldown on P2.6
    P2OUT |= (1 << 6); 
}

/*---------------------------------------------------------------------------*/

/**
 *
 * This function returns whether the button1 is pressed or not.
 *
 * \return 0 if the button 1 is not pressed.
 */
/*---------------------------------------------------------------------------*/


int buttons_1pressed(void)
{
	return (!(BUTTON1_IN & BUTTON1_PIN));
}

/*---------------------------------------------------------------------------*/

/**
 *
 * This function returns whether the button2 is pressed or not.
 *
 * \return 0 if the button 2 is not pressed.
 */
/*---------------------------------------------------------------------------*/
	
	
int buttons_2pressed(void)
{
	return (!(BUTTON2_IN & BUTTON2_PIN));
}

int button1_pressed(void)
{
	return buttons_1pressed();
}

int button2_pressed(void)
{
	return buttons_1pressed();
}

