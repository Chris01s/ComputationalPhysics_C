#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
	return 1 + 0.5*tanh(2*x);
}

float forward_diff(float x,float h){
	return (f(x+h) - f(x))/h;
}

float central_diff(float x, float h){
	return (f(x+h/2) - f(x-h/2))/h;
}


int main(void){
	
	float h, x, fprime;
	
	h = 1E-3;
	
	for(x = -2; x <= 2; x += 0.04){
		fprime = central_diff(x,h);
		printf("%f\t%f\t%f\n",x,fprime,1/(cosh(2*x)*cosh(2*x)));
	}
	
	return 0;
}