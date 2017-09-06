#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N	200
#define M	10000

float f1(float a, float x){
	
	return pow(x,a-1)*exp(-x);
}

float f2(float a, float z){
	
	return exp((a-1)*log(z/(1-z)) - z/(1-z))/((1-z)*(1-z));
}

float f3(float a, float z){
	
	return pow(z/(1-z),a-1) * exp(-z/(1-z))/((1-z)*(1-z));
}

double gamma1(float C, float x[], float w[]){
	
	float s;
	int k;
	
	s = 0.0;
	for(k = 0; k < N; k++)
		s += w[k]*f2(C,x[k]);
	
	return s;
}

double gamma2(float a, float b, float C){
	
	double Simp;
	float h;
	int k;
	
	Simp = 0;
	h = fabs(a-b)/M;
	
	for(k = 0; k < M; k++){
		if(k%2 != 0)
			Simp += 4*f2(C,a + k*h);
		else
			Simp += 2*f2(C,a + k*h);
	}
	
	return Simp*h/3.0;
}

int main(void){
	
	float res1, res2, a, b;
	float C[3] = {3,6,10};
	float x[N], w[N];
	int i;
	
	a = 0.0;
	b = 1.0;
	
	i = 0;
	while(scanf("%f\t%f", &w[i], &x[i]) != EOF){
		x[i] = 0.5*(b-a)*x[i] + 0.5*(b+a);
		w[i] = 0.5*(b-a)*w[i];
		i++;
	}
	
	for(i = 0; i < 3; i++){
		res2 = gamma2(a,b,C[i]);
		res1 = gamma1(C[i],x,w);
		printf("%f\t%f\n",res1,res2);
	}
	
	return 0;
}
	
	
	