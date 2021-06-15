#include "func_prototype.h"
#include "tm4c123gh6pm.h"
#include "GPS_Receive.h"
#include "parser.h"
#include <string.h>
#include <stdlib.h>

void SystemInit(void)
{

}

int main(void)
{	
		char * distLCD;
    double dist=0;
    double coordiantes [2][2];
    char *received;
    double numberinD;
    char * lat ;
    char* longi;
    int INT;	
		double d2;
		char* dist2;

	delay_ms(20);
	port_init();
	delay_ms(20);
	uart_init();
	delay_ms(50);
	LCD_init();
	delay_ms(20);

			
	while(1)
	{

		 //received = UART1_Read();
		//LCD_Data(received);
			received = get_NEMA_str();
			delay_ms(50);
		received = strtok(received , ",");
received= strtok(NULL , ",");
received= strtok(NULL , ",");
numberinD = strtod(received,NULL);
INT = (int) numberinD/100;

 numberinD= INT +  (((numberinD) -  (INT*100))/60 ) ; 

coordiantes[0][0] = numberinD; // lat`1
received= strtok(NULL , ",");
received= strtok(NULL , ",");
numberinD = strtod(received,NULL);
INT = (int) numberinD/100;
 numberinD= INT +  (((numberinD) -  (INT*100))/60 ) ; 

 coordiantes[0][1] = numberinD; // long 1
 
 delay_ms(500);
 
received = get_NEMA_str();  // second point

received = strtok(received , ",");
received= strtok(NULL , ",");
received= strtok(NULL , ",");
numberinD = strtod(received,NULL);
INT = (int) numberinD/100;

 numberinD= INT +  (((numberinD) -  (INT*100))/60 ) ; 


coordiantes[1][0] = numberinD; // lat2 
received= strtok(NULL , ",");
received= strtok(NULL , ",");
numberinD = strtod(received,NULL);
INT = (int) numberinD/100;
 numberinD= INT +  (((numberinD) -  (INT*100))/60 ) ; 
 coordiantes[1][1] = numberinD; // long 2

 dist += calculate_distance(coordiantes[0][0] ,coordiantes[1][0] ,coordiantes[0][1] ,  coordiantes[1][1] ); // distance calculTOR
 distLCD = doubleToStr(dist);
 d2 = strtod(distLCD,NULL);
 dist2=doubleToStr(d2);
delay_ms(50);
	LCD_prnt_str(dist2);
	
	delay_ms(100);
	LCD_comm(0x01);
	

		//received = strtok(received , ",");
		//received= strtok(NULL , ",");
		//received= strtok(NULL , ",");
		//numberinD = strtod(received,NULL);
		//lat=doubleToStr(numberinD);
		//rvereseArray(lat , 0 , 3);
		//LCD_prnt_str(lat);
			//cordinates = getPosition(received);
//g = doubleToStr(cordinates[0]);
			//LCD_prnt_str(g);
		//LCD_Data('a');
			delay_ms(1000);
			
		turnOnRedLed(dist);
		


		
	}
	
	
	
	
return 0;
}