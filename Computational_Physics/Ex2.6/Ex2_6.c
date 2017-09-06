#include <stdio.h>
#include <math.h>
#include <float.h>
#define pi	4*atan(1)


float Orbital_Mech(float l1, float v1, float M,float result[]);

int main(void)	{
	
	float l1,v1,M,result[2] = {};
	
	M = 1.989E30; //Sun's mass

	//conditions (Earth)
	l1 = 1.471E11;
	v1 = 3.0287E4;
	Orbital_Mech(l1,v1,M,result);
	printf("%f\t%f\n",result[0],result[1]);

	l1 = 8.7830E10;
	v1 = 5.4529E4;
	Orbital_Mech(l1,v1,M,result);
	printf("%f\t%f\n",result[0],result[1]);
	
	return 0;
}


float Orbital_Mech(float l1, float v1, float M, float result[])	{
    /*Returns the orbital period and
    eccentricity of the orbiting body*/
    
	float v2,l2,a,b,G;
	
	//calculations
    G = 6.67E-11;
    v2 = 2*G*M/(l1*v1) - v1;
    l2 = l1*v1/v2;
    a = (l1 + l2)/2;
    b = sqrt(l1*l2);

	//Calculate Period and eccentricity
    result[0] = 2*pi*a*b/(l1*v1*365.65*24*3600);
    result[1] = (l2 - l1)/(l2 + l1);
	
    return *result;
}