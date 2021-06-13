#include "tm4c123gh6pm.h"
#include "func_prototype.h"



void delay_ms(int n)
{
	int x , y;
	for(x = 0; x < n ; x++){
		for(y = 0 ; y < 3180;y++)
		{}
	
	}
}
void delay_us(int n)
{
 int i,j;
 for(i=0;i<n;i++){
	for(j=0;j<3;j++){}
	
	}

}

// RS = 0 for command while RS = 1 for   Data 
// RW = 0 for write on LCD (our case)or RW = 1 to Read from LCD
// RS for PD0 , RW for PD1 and E for PD2
void LCD_comm (unsigned char command)
{
		
    GPIO_PORTB_DATA_R =command;
    GPIO_PORTD_DATA_R &= ~0X01; 
    GPIO_PORTD_DATA_R &= ~0X02; 
    delay_ms(1);
    GPIO_PORTD_DATA_R |= 0x04 ; // E=1
    delay_us(1); 
    GPIO_PORTD_DATA_R &= ~ 0x04 ; // E=0
    delay_us(5);

} 


void LCD_Data(unsigned char data) 
{ 			
	   //Pin b6 is damaged and gives 1 at all times , so I am using pin A3 
	   //It appears that using B and D together for the LCD makes some conflict in the signals
	   if(data & 0x40) GPIO_PORTA_DATA_R |= (0x08);

	   GPIO_PORTB_DATA_R = data;
           GPIO_PORTD_DATA_R |= 0x01 ; // RS=1
	   GPIO_PORTD_DATA_R &= ~ 0x02 ; // RW=0
	   GPIO_PORTD_DATA_R |= 0x04 ; // E=1
	   delay_us(1);
	   GPIO_PORTD_DATA_R &= ~ 0x04 ; // E=0
           delay_us(1);
//making sure to clear all data	
	GPIO_PORTB_DATA_R=0;
	GPIO_PORTA_DATA_R &=~ (0x08);
}
	

void LCD_init(void)
{
	
         delay_ms(20);
         LCD_comm(0x38); // Select 8-bit Mode of LCD
         delay_us(50);
         LCD_comm(0x0F); // display on , cursor blinking
	 delay_us(50);
	 LCD_comm(0x06); //auto increment cursor
	 delay_us(50);
	 LCD_comm(0x01); //clear display
	 delay_ms(5);

}

//Function to take string and print it on LCD
void LCD_prnt_str( char *str)
{
	int counter;
	for(counter = 0; str[counter] != '\0'; counter++) // \0 means end of the string
	{
		LCD_Data(str[counter]);
		delay_ms(1);
	}
	


		




	



}
