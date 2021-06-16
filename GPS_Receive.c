#include "func_prototype.h"
#include "stdint.h"
#include "func_prototype.h"
#include "string.h"


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


char * revCharArr(char string[]){
    //maximum number 5
    static char result[5];
    int nullIndex = strlen(string);
    for(int i = strlen(string) - 1 ; i >= 0 ; i--){
        if(string[i] == '\0') {
            nullIndex = i;
            break;
        }
    }
    for(int i = 0 ; i < nullIndex ; i++){
        result[i] = string[nullIndex - i - 1];
    }
    return result;
}


