#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float f(float x) {
	return exp(x)*x*x*x*x/((exp(x) - 1)*(exp(x) - 1));
}

float CV(float T, float x[], float w[]) {
	
	int i;
	float xp,wp;
	float cv;
	
	cv = 0;
	for(i = 0; i < sizeof(x)/sizeof(float); i++) {
		xp = 0.5*T*(x[i] + 1.0);
		wp = 0.5*T*w[i];
		cv += f(xp)*(wp);
	}
	
	return cv;
}

int main(void) {
	
	int i;
	float x[50],w[50],T,V;
	double rho,theta,Boltz,kappa;
	float heat_cap;
	
	V = 1E-3;
	rho = 6.022E28;
	theta = 428;
	Boltz = 1.38E-23;

	i = 0;
	while(scanf("%f\t%f",&x[i],&w[i]) != EOF)
		i++;

	
	for(T = 5; T < 500; T+=5){
		kappa = 9*V*rho*Boltz*(T/theta)*(T/theta)*(T/theta);
		heat_cap = CV(theta/T,x,w)*kappa;
		printf("%g\t%g\n",T,heat_cap);
	}
	
	return;
}
		
		
	
	
