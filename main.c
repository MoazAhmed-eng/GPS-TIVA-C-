#include "func_prototype.h"
#include "tm4c123gh6pm.h"

void SystemInit(void)
{

}

int main(void)
{	
	unsigned char x[]="hello";
			port_init();
	delay_ms(50);
	LCD_init();
	delay_ms(20);
	LCD_Data('8');
		delay_ms(1);
	LCD_prnt_str(x);
    for (;;)
    {

    }
		return 0;

}

	





