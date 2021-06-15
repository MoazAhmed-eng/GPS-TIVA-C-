#include "func_prototype.h"
#include "stdint.h"
#include "func_prototype.h"

char* get_NEMA_str()
{
	int i =0;
	int p =1;
	static  char tmp_str[50];
	 char received;
while (p){
	 received = UART1_Read();
	if(received=='$') {
	
		received = UART1_Read();

		if(received=='G') {

						received = UART1_Read();


				if(received=='P') {
						received = UART1_Read();

						if(received=='R') {
											received = UART1_Read();
																if(received=='M') {
																					received = UART1_Read();

																							if(received=='C') {
																										received = UART1_Read();

																												if(received==',') {

																													for(i = 0 ; i< 50 ; i++)
																													{
																														tmp_str[i]=UART1_Read();

																													}
																													p =0;
																												}}}}}}


	}
}

	
return tmp_str;
	
}


