#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define	N	1000
#define pi 	4*atan(1)

float f(float x){
	return x*x*x/(exp(x) - 1);
}

float fprime(float z){
	return f(z/(1-z))/((1-z)*(1-z));
}


int main(void){
	
	float a,b,c,hbar,sig,x[N],w[N],T;
	double k;
	int i;
	
	a = 0;
	b = 1;
	k = 8.31/6.022E23;
	c = 1/sqrt(4*pi*1E-7*8.85E-12);
	hbar = 6.63E-34/(2*pi);
	
	i = 0;
	while(scanf("%f\%f",&w[i],&x[i]) != EOF){
		x[i] = 0.5*(b-a)*(x[i] + 1.0);
		w[i] = 0.5*(b-a)*w[i];
		i++;
	}
	
	sig = 0.0;
	for(i = 0; i < N; i++)
		sig += fprime(x[i])*w[i];
	
	sig = sig*pow(k,4)/(pow(2*pi*c,2)*hbar*hbar*hbar);
	//printf("%g\n",sig);
	
	for(T = 300; T < 1000; T +=10)
		printf("%f\t%f\n",T,T*T*T*T*sig);
		
	return;
}

	