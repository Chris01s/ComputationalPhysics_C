#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N	100

float f(float x, float y, float z){
	return 1/pow(x*x + y*y + z*z,1.5);
}

float Force(float z, float xp[], float yp[], float wp[]){
	
	float s;
	int i, j;
	
	s = 0.0;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			s += wp[i]*wp[j]*f(xp[i],yp[j],z);
		
	return s;
}

int main(void){
	
	double F, G;
	float w[N], x[N], y[N], z, m, ro;
	int i, a, b;
	
	G = 6.674E-11;
	m = 1;
	ro = 100; 
	
	i = 0;
	a = -5;
	b = 5;
	
	while(scanf("%f\t%f",&w[i],&x[i]) != EOF){
		w[i] = 0.5*(b-a)*w[i];
		x[i] = 0.5*(b-a)*x[i] + 0.5*(b+a);
		y[i] = x[i];
		//printf("%f\t%f\n",w[i],x[i]);
		i++;
	}
	
	for(z = 0.0; z < 10; z += 0.2){
		F = Force(z,x,y,w)*G*m*ro*z;
		printf("%f\t%g\n",z,F);
	}
	
	return 0;
}

		
	
	