#include "func_prototype.h"
#include "tm4c123gh6pm.h"

void SystemInit(void)
{

}

int main(void)
{	
	unsigned char x[]="hello 1 2 ";
	port_init();
	delay_ms(50);
	LCD_init();
	delay_ms(20);
	LCD_Data('a');
	delay_ms(1);
	LCD_prnt_str(x);
		LCD_Data('8');
	delay_ms(1);

    for (;;)
    {
	turnOnRedLed(120);
    }
return 0;

}

	





