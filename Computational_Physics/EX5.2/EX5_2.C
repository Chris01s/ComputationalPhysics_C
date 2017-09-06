#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float f(float x) {
	return x*(x*x*x - 2) + 1;
}

float Trapezoid(float a,float b, float N) {
	float h, I;
	int k;
	
	h = fabs(a - b)/N;
	I = 0.5*(f(a) + f(b));
	
	for(k = 1; k < N; k++)
		I += f(a + k*h);
	
	return h*I;
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
	
	float a,b,N, Ns[3] = {10,100,1000};
	float T, S;
	int i;
	
	N = 10;
	a = 0;
	b = 2;
	S = Simp(a,b,N);
	printf("%f\t%f\n",S,fabs(S - 4.4)/4.4);
	
	for(i = 0; i<3; i++) {
		T = Trapezoid(a,b,Ns[i]);
		S = Simp(a,b,Ns[i]);
		printf("N: %f Trapezoid: %f Simpson: %f\n", Ns[i],T,S);
	}
	
	return 0;
}
	
	