#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void)	{
	
	double x,xprime,v,gamma,time;

	//raw input
	printf("Enter distance travelled(lyrs), and the speed of craft (fraction of c): ");
	scanf("%lf",&x);
	scanf("%lf",&v);
	
	//calculate gamma factor
	gamma = 1/sqrt(1 - v*v);
	
	//simple time-distance relationship: note the time will appear dilated
	//on the craft from this frame of reference
	time = x/v;
	printf("the time taken to reach the planet as seen from Earth: %.3f yrs\n",time);

	xprime = x/gamma;
	time = xprime/v;
	printf("Length contracted to %.7f lyrs and takes %.7f yrs\n",xprime,time);
	
	return 0;
}