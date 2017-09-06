#include <math.h>
#include <stdio.h>


int main(void)	{

	double height, gravity, time;
	
	//input height in metres
	scanf("%lf",&height);
	
	//use simple kinematics equations
	gravity = 9.81; //m/s
	
	//distance = 1/2 * g * t^2: rearrange for t 
	time = sqrt(2.0*height/gravity);
	printf("time for the ball to reach the ground is %f\n",time);
	
	return 0;
}
