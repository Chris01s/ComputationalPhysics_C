#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define N	50
#define pi	4*atan(1.0)

double I_I0(float x, float z, float t[], float w[]) {
	
	float U, lambda, tp[N], wp[N], c, s;
	double I;
	int i;
	
	lambda = 1.0;
	U = x*sqrt(2/(lambda*z));

	for(i = 0; i < N; i++) {
		tp[i] = 0.5*U*t[i] + 0.5*U;
		wp[i] = 0.5*U*w[i];
		//printf("%f\n",tp[i]);
	}
	
	s = 0.0;
	c = 0.0;
	for(i = 0; i < N; i++) {
		s += sin(0.5*tp[i]*tp[i]*pi)*wp[i];
		c += cos(0.5*tp[i]*tp[i]*pi)*wp[i];
	} 
	
	//printf("%f\n",c);
	I = ((2.0*c + 1.0)*(2.0*c + 1.0)) + ((2.0*s + 1.0)*(2.0*c + 1.0));
	
	return I;
}

int main(void) {
	
	float x, z;
	float t[N],w[N];
	double I;
	int i;
	
	i = 0;
	while(scanf("%f\t%f",&w[i],&t[i]) != EOF)
		i++;
	
	
	z = 3.0;
	for(x = -5; x < 5; x += 0.05) {
		I = I_I0(x,z,t,w)/8.0;
		printf("%g\t%f\n", x, I);
	}
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	