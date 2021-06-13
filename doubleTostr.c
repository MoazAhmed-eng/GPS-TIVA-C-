#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "func_prototype.h"


char* doubleToStr (double dobl)
{
  static char arr[5];
  int i;
  int intDobl = (int) dobl;
  for(i=0 ; intDobl != 0 ; i++)
  {
    arr[i] = (intDobl%10) + 48 ; // To make it ASCII 
    intDobl/=10;
    if(intDobl==0)
    {
      arr[i+1]='\0';
    }
  }

  return arr;

}