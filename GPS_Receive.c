#include "func_prototype.h"
#include "stdint.h"
#include "GPS_Receive.h"

  char* get_NEMA_str()
{
	static  char tmp_str[100];
	 char received;
	int loop=1;
	
	
	
	while(loop)
		
	{
	int j;
	received=UART1_Read(); //First Element
	for(j=0;((j<100)&&(received!=0x0A));j++)
	{
		tmp_str[j] = received;
		received=UART1_Read();
	}
	
	tmp_str[j]='\0';
	
	if(tmp_str[0]=='$' && tmp_str[3]=='R') //if true -> recieved is GPRMC
	{
			loop=0;
	}
	
}
	
return tmp_str;
	
}