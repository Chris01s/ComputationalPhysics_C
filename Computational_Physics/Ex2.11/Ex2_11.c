#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double fact(double n) {
	if(n <= 1)
		return 1;
	else
		return n*fact(n-1);
}

double binomial(double n, double k) {
	return fact(n)/(fact(k)*fact(n-k));
}

double Prob(double n,double k) {
	
	double i;
	double probablity;
	
	probablity = 0;
	
	for(i = k; i < n+1; i++)
		probablity += binomial(n,i)/pow(2,n);
	
	return probablity;
}

void PascalTriangle(double N) {
	
	double n, k;
	
	for(n = 0; n < N; n++) {
		printf("\n");
		for(k = 0; k < n+1; k++) 
			printf("%.0f\t",binomial(n,k));
	}
	return;
}
		

int main (void) {
	
	double n, k, N;
	double prob,pTotal;
	
	N = 20;
	PascalTriangle(N);
	
	n = 100;
	k = 60;
	prob = binomial(n,k)/pow(2,n);
	pTotal = Prob(n,k);

	printf("\n\n%f\t%f", prob,pTotal);
	
	return 0;
}
	
