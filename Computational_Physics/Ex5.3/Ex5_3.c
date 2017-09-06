#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float f(float t) {
	return exp(-t*t);
}

float Simp(float a, float b, float N) {
	
	float h, S;
	int k;
	
	h = fabs(a-b)/N;
	S = 0;
	
	for(k = 1; k < N; k++) {
		if(k%2 != 0)
			S += 4*f(a+k*h);
		else
			S += 2*f(a+k*h);
	}
	return h*(f(a) + f(b) + S)/3.0;;
}


int main() {
	
	float delta, b, x, N;
	float Res1, nElements;
	
	N = 10;
	delta = 0.1;
	x = 3;	
	
	Res1 = 0.0;
	
	for(b = 0; b < x; b += delta) {
		printf("%f\t%f\n",b,Res1);
		Res1 += Simp(b,b+delta,N);
	}
		
	return 0;
	
}
		
