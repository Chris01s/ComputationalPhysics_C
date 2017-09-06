#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define	N	100

float V(float x) {
	return x*x*x*x;
}

float Period(float a, float x[], float w[]) {
	
	float xp, wp, E, f, T;
	int i;

	T = 0;
	E = V(a);
	for(i = 0; i < sizeof(x)/sizeof(float); i++) {
		xp = 0.5*a*(x[i] + 1);
		wp = 0.5*w[i]*a;
		f = 1/sqrt(E - V(xp));
		T += f*wp;
	}
	
	return T;
}
		

int main(void) {
	
	int i;
	float m = 1.0, a, T;
	float x[N], w[N];
	
	//READ IN N-POINT GAUSSIAN QUADRATURE
	i = 0;
	while(scanf("%f\t%f",&x[i], &w[i]) != EOF)
		i++;
	
	//Perform the integral for a range of amplitudes
	for(a = 0; a <= 2; a += 0.02) {
		T = Period(a,x,w)*sqrt(8*m);
		printf("%f\t%f\n",a,T);
	}

	return 0;
}





	