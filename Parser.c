#include "stdlib.h"
#include "string.h"
#include "parser.h"

double *getPosition(  char *string)
{
    static double coordinates[2];
    char *parsed[20];
    
        int i = 0;
        char *splitted;
        splitted = strtok(string, ",");
        while (splitted != NULL)
        {
            parsed[i++] = splitted;
            //Continue splitting the same string
            splitted = strtok(NULL, ",");
            if (i == 7)
                break;
        }
    
    coordinates[0] = strtod(parsed[3] , NULL);
    coordinates[1] = strtod(parsed[5] ,		 NULL);
    return coordinates;
}