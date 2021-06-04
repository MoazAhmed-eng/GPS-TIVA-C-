#include "sys-tic-timer.h"
#include "tm4c123gh6pm.h"
#define CLOCK_CYCLES_PER_MS 16000


void sys_tic_init(void)
{
  NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE; // Enable =0
	NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;    // Reload = 0x00FFFFFF
	NVIC_ST_CURRENT_R = NVIC_ST_CURRENT_S;  // Current = 0
	NVIC_ST_CTRL_R |= (NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_ENABLE); // Clock source and Enable On	
}


void sys_tic_wait1ms(void)
	{
	NVIC_ST_RELOAD_R = CLOCK_CYCLES_PER_MS - 1; // -1 becasue the flag is raised after an extra count
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&NVIC_ST_CTRL_COUNT) != NVIC_ST_CTRL_COUNT); // When the Flag is 1  , EXIT
}




