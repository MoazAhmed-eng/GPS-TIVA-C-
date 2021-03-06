#include "tm4c123gh6pm.h"
#include "func_prototype.h"


void port_init(void)
{
/*

Port B --> LCD data
Port D --> LCD control
Port F --> LED

*/
	
	// Intializing port A to compensate for the broken b6 pin
	
	SYSCTL_RCGCGPIO_R|=0x01;
	GPIO_PORTA_CR_R = 0xFF;
	GPIO_PORTA_DIR_R = 0xFF;				//Set portB pins to output
	GPIO_PORTA_AFSEL_R = 0x00;				//disable portB pin alternate function
	GPIO_PORTA_PCTL_R = 0x00000000;			//PORTB AS GPIO
	GPIO_PORTA_AMSEL_R = 0x00;				//disable analog signals
	GPIO_PORTA_DEN_R = 0xFF;				//enable digital signals
//Intializing ports B , D and F

//Intializing Clock for ports B,D,F
SYSCTL_RCGCGPIO_R|=0x2A;
//while((SYSCTL_PRGPIO_R&(0x2A))==0);
//Unlocking
GPIO_PORTD_LOCK_R= GPIO_LOCK_KEY;
GPIO_PORTF_LOCK_R= GPIO_LOCK_KEY;
//pinF0
GPIO_PORTF_CR_R|=0x13;
//pinD7
GPIO_PORTD_CR_R|=0xFF;

// Enabling Digital

//For All pins in B
GPIO_PORTB_DEN_R|=0xFF;
//For Pins F0,F1,F4
GPIO_PORTF_DEN_R|=0xFF;
// For LCD Control
GPIO_PORTD_DEN_R|=0xFF;

// Disabling Analog function
GPIO_PORTB_AMSEL_R &=~0xFF;
GPIO_PORTD_AMSEL_R =0x00;
GPIO_PORTF_AMSEL_R &=~0x13;

// Disabling AFSEL
GPIO_PORTB_AFSEL_R&=~0xFF;
GPIO_PORTD_AFSEL_R=0x00;
GPIO_PORTF_AFSEL_R&=~0x13;

//Choosing GPIO
GPIO_PORTB_PCTL_R&= 0;
GPIO_PORTD_PCTL_R= 0;
GPIO_PORTF_PCTL_R&= 0;

//Initalizing internal Pull up resistor for F0,F4
GPIO_PORTF_PUR_R|=0x11;

//selecting the direction
GPIO_PORTB_DIR_R|=0xFF;
GPIO_PORTD_DIR_R|=0xFF;
GPIO_PORTF_DIR_R|=0x0E;



}
