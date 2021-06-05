#include "tm4c123gh6pm.h"
#include "func_prototype.h"


void uart_init(void)
{
//This better will need to get edited as pins A0,A1 are not visible on the board itself	
//UART initialization (A0,A1)

//Initalizing Clock for UART0
SYSCTL_RCGCGPIO_R|=0x01;
SYSCTL_RCGCUART_R|=0x01;
 // while((SYSCTL_PRUART_R&(0x01))==0);
	
	// Enabling Digital For Pins A0,A1
GPIO_PORTA_DEN_R|=0x03;
//Disabling Analog
GPIO_PORTA_AMSEL_R &=~0x03;
//Enabling AFSEL
GPIO_PORTA_AFSEL_R&=0x03;
//Choosing the wanted function
GPIO_PORTA_PCTL_R|=0x00000011;
//Selecting the direction
GPIO_PORTA_DIR_R|=0x02;
//Disabling
UART0_CTL_R&=~0x0001;
//Adding the values for the integer and fractional baud rate
UART0_IBRD_R|=104;
UART0_FBRD_R|=11;
//determining the length of the data as 8 bits and one stop bit and FIFO mode ON
UART0_LCRH_R|=0x70;
//Now Enabling
UART0_CTL_R=0x0301;

}
