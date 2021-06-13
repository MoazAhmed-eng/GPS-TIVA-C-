#include "func_prototype.h"
#include "tm4c123gh6pm.h"
#include "GPS_Receive.h"
#include "parser.h"

void SystemInit(void)
{

}

int main(void)
{	
	delay_ms(20);
	port_init();
	delay_ms(50);
	LCD_init();
	delay_ms(20);

	while(1)
	{
		int p ;
		int i ;
		double total_dist;
		char *arr; // to Hold total distance in char[]
		static double array2Pt[2][2]; // to hold two points
		static double* array_coordinates; // to hold lat,long
		static  char *array; //to hold the  un-parsed string
		//To Get First Point
		array=get_NEMA_str();
		array_coordinates = getPosition(array);

		for(i=0 ; i<2 ;i++)
		{
			array2Pt[0][i] = *array_coordinates;
			array_coordinates++;
		}
		
		//To Get Second Point
		
		array=get_NEMA_str();
		for( p=0 ; p<2 ;p++)
		{
			array2Pt[1][p] = *array;
			array++;
		}
		
		total_dist+=calculate_distance( array2Pt[0][0] ,array2Pt[1][0] , array2Pt[1][0] , array2Pt[1][1] );
		arr = doubleToStr(total_dist);
		LCD_prnt_str(arr);
		delay_ms(500);
		
	}
	
	
	
	
return 0;
}

	





