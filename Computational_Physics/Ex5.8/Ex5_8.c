#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float f(float x);
float T(float a, float b, float N);

int main(void) {
	
	//tolerance level and two estimates of the integral
	float tol, I1, I2; 
	//These are just variables to divide 
	//the process into seperate parts that enable
	//it to be adaptive.
	float S1, S2, T1, T2;
	//upper(b) and lower(a) limits of integral, No. of steps(N) and step size(h)
	float a, b, N, h;
	//iterator
	int k;
	
	//set up initial conditions
	N = 1; //one step
	a = 0;
	b = 1;
	h = fabs(a-b)/N;
	tol = 1E-6;
	
	//calculate initial estimate of the integral
	S1 = (f(a) + f(b))/3;
	for(k = 2; k < N-1; k += 2)
		S1 += 2*f(a + k*h)/3;
	
	T1 = T(a,b,N);
	I1 = h*(S1 + 2*T1);
	I2 = 0;
	//Now, double number of steps and use initial estimate S1,T1 to 
	//calculate new more accurate estimate S2 = S1 + T1.
	//Keep improving on the accuracy until the error between current
	//and previous estimates (I1-I2)/3 < tolerance level.
	while(fabs(I1-I2)/15 > tol) {
		N *= 2;
		h = fabs(a-b)/N;
		T2 = T(a,b,N);
		S2 = S1 + T1;
		I2 = h*(S2 + 2*T2);
		printf("%f : %f\n",N,I2);
		if(fabs(I1-I2)/15 < tol)
			break;
		else {
			I1 = I2; I2 = 0;
			S1 = S2; S2 = 0;
			T1 = T2; T2 = 0;
		}
	}
		
	return 0;
	
}

float f(float x) {
	
	return sin(sqrt(100*x))*sin(sqrt(100*x));
}

float T(float a, float b, float N) {
	
	float T1,h;
	int k;
	
	T1 = 0.0;
	h = fabs(a-b)/N;
	for(k = 1; k < N; k += 2) 
		T1 += f(a + k*h);
	T1 *= 2/3.0;
	
	return T1;
}

		
	
	
	