#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI	4*atan(1)

float f(float m, float x, float theta);
float J(float m, float x);

int main() {
	
	float B1, B2, B3, x;
	float M, m[3] = {0,1,2};
	
	M = 100;
	
	for(x = 0; x <= 20; x += 20/M) {
		B1 = J(m[0],x)/PI;
		B2 = J(m[1],x)/PI;
		B3 = J(m[2],x)/PI;
		printf("%f\t%f\t%f\t%f\n", x, B1, B2, B3);
	}
	
	return 0;
}
		

//Bessel function
float f(float m, float x, float theta) {
	return cos(m*theta - x*sin(theta));
}

//integral of Bessel function
float J(float m, float x) {
	
	float h, S, N, a, b;
	int k;
	
	N = 100;
	a = 0;
	b = PI;
	h = fabs(a-b)/N;
	S = 0;
	
	//Simpson's Rule
	for(k = 1; k < N; k++) {
		if(k%2 != 0)
			S += 4*f(m,x,a+k*h);
		else
			S += 2*f(m,x,a+k*h);
	}
	return h*(f(m,x,a) + f(m,x,b) + S)/3.0;
}
	