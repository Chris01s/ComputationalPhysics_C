#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
	return x*x;
}

double forward_diff(double x,double h){
	return (f(x+h) - f(x))/h;
}

double central_diff(double x, double h){
	return (f(x + h/2) - f(x - h/2))/h;
}


int main(void){
	
	double h, x;
	double central, forward;
	int a;
	
	x = 1.0;
	for(a = -10; a <= 16; a++){
		h = pow(10,a);
		central = central_diff(x,h);
		forward = forward_diff(x,h);
		printf("%f\t%e\t%e\n",log10(h),(central-2.0)/2,(forward-2.0)/2);
	}
	
	return 0;
}