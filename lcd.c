#include "tm4c123gh6pm.h"
#include "sys-tic-timer.h"
#include "func_prototype.h"




// RS = 0 for command while RS = 1 for   Data 
// RW = 0 for write on LCD (our case)or RW = 1 to Read from LCD
// RS for PD0 , RW for PD1 and E for PD2
void LCD_Command (unsigned char command)
{
    GPIO_PORTD_DATA_R = 0X00; //RS =0,RW=0,E=0
		GPIO_PORTB_DATA_R =command;
    GPIO_PORTD_DATA_R = 0x04 ; // E=1
		delay ((uint32_t) 0);
	  GPIO_PORTD_DATA_R = 0x00 ; // E=0
		delay ((uint32_t) 2);
 } 


void LCD_Data(unsigned char data) 
{ 
    GPIO_PORTD_DATA_R = 0x01 ; // RS=1,RW=0,E=0
		GPIO_PORTB_DATA_R = data;
    GPIO_PORTD_DATA_R |= 0x04 ; // E =1
	  GPIO_PORTD_DATA_R = 0x00 ; // E=0 , RS=1
		delay ((uint32_t) 0);

}

void LCD_init(void)
{
}
;





	

			
}


