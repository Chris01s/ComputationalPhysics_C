#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define PI	4*atan(1)

float f(float x) {
	return sqrt(1 - x*x);
}

float integral(float N) {
	
	int k;
	float h, integrate;
	
	integrate = 0.0;
	h = 2.0/N;
	for(k = 0; k < N; k++) 
		integrate += h*f(-1 + h*k);
	
	return integrate;
}


int main() {

	float N, result;
	
	N = 100;
	result = integral(N);
	printf("%f\n",result);
	
	for(N = 1E3; N < 10E3; N += 1E3) {
		result = integral(N);
		printf("%f\n",result);
	}
	
	return 0;
}


		