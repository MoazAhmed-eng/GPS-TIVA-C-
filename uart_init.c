#include "tm4c123gh6pm.h"
#include "func_prototype.h"


void uart_init(void)
{
// initialzing UART1 which corresponds to PC4 and PC5	
// This initialization is based on the following : 1. tiva frequency = 16Mhz   2. BR of neo 6m = 9600 bps (default BR )

// Seting the clock for both UART1 and Port c
	
SYSCTL_RCGCGPIO_R |= 0x02 ; 
SYSCTL_RCGCUART_R |= 0x04 ;
	
// Disabling UART1 
	
UART0_CTL_R &= ~ (0x01) ;

// UART1 configuration

UART0_LCRH_R = 0x70 ; // fifo enabled (bit4=1) and data length is 8 bits ( bit5 = bit6 = 1 )
UART0_IBRD_R = 140 ;	// divisor = (16M/(16*9600)) = 104.167  1) IBRD = 104   2) FBRD = (0.167*64) + 0.5 = 11 
UART0_FBRD_R = 11 ;	
	
// Enabling UART1 , TX and RX 

UART0_CTL_R |= 0x301 ; // UART1 enabled (bit0=1) and RX and TX are enabled (bit4=bit5=1)

//  Port C configuration
	
GPIO_PORTC_AFSEL_R |= 0x30 ;
GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0xFF00FFFF ) + 0x00220000 ; // Determining pic C4 and C5 as UART1
GPIO_PORTC_DEN_R |= 0x30 ;
GPIO_PORTC_AMSEL_R &= ~ (0x30) ;
	
}
