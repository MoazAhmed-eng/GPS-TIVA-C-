#include "tm4c123gh6pm.h"
#include "func_prototype.h"

void turnOnRedLed(unsigned char distance)
{
if (distance>=100)
					GPIO_PORTF_DATA_R|=0x02;
	
}
//was used for testing blinking
void turnOffRedLed(void)
{
 					GPIO_PORTF_DATA_R&=0;
}
