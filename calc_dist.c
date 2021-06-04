#include<math.h>
#include "func_prototype.h"
#define PI 3.14159265358979323846
#define RADIUS 6371 // earth radius in km


double degToRad(double deg)
{
    return (deg*PI/180);
}

double calculate_distance ( double lat1 , double lat2 , double long1 , double long2 )
{
    double distance=0;
	  double z=0;
    double x =degToRad(lat2-lat1);
    double y =degToRad(long2-long1);
    // convert lattitudes into radians
    lat1 = degToRad(lat1);
    lat2 = degToRad(lat2);
    // applying haversine formula 
    z = pow(sin(x*0.5),2) + cos(lat1) * cos(lat2) * pow(sin(y*0.5),2);
    distance = 2*RADIUS *1000 * asin(sqrt(z)); // distance in meter
    return distance;
}





