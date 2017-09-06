#include <stdio.h>
#include <math.h>
#include <float.h>
#define	PI	4*atan(1)

int main(void)	{
	double G,R,M,time,height;
	
	//constant
	G = 6.67e-11;
	R = 6.371e6; //metres
	M = 5.97e24; //kilogramms
	
	scanf("%lf",&time);//mins
	time *= 3600; //secs
	height = pow(G*M*time*time/(4.0*PI*PI),1/3.0) - R;
	printf("height of the object is %f\n",height);
	
	return 0;
}
