/**
 * The Buttons driver defines a number of macros allowing Button control.
 * There are two Button on the platform in pinw 1.4 and 2.6.
 * 
 */

/**
 * \file
 * \brief Buttons driver.
 * \author Joaquin Juan Toledo <joaquin.j.toledo@gmail.com>
 * \date Agoust 2010
 */


#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <msp430f5435a.h>

/**********************
* Buttons
**********************/

#define BUTTON1_IN	P1IN
#define BUTTON2_IN	P2IN

#define BUTTON1_PIN		(1 << 4) // pin 1.4
#define BUTTON2_PIN		(1 << 6) // pin 2.6

/**
 * \brief Configure the IO port of the MSP430.
 * 
 * This function should be called first in order for the others to work. 
 * \hideinitializer
 */

void buttons_init(void);

int buttons_1pressed(void);
int buttons_2pressed(void);
int button1_pressed(void);
int button2_pressed(void);

#endif /*BUTTONS_H_*/
