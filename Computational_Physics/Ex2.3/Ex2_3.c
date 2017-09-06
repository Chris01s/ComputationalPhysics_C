#include <stdio.h>
#include <math.h>
#include <float.h>
#define	PI	4*atan(1)

int main(void)	{
	
	double x,y,r,theta;

	//raw input
	printf("Enter coordinates: ");
	scanf("%lf",&x);
	scanf("%lf",&y);
	
	//calculate radius
	r = sqrt(x*x + y*y);
	theta = acos(x/r);
	printf("the radius is %.3f and the angle is %.3f\n",r,theta);

	x = r*cos(theta);
	y = r*sin(theta);
	printf("x is %.3f and y is %.3f",x,y);
	
	return 0;
}
