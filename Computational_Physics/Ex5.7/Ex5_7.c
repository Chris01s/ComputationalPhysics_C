#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float f(float x);
float Trapezoid(float a, float b, float N);

int main(void) {
	
	//tolerance level, and two estimates of the integral
	float tol, I1, I2; 
	//upper and lower limits of integra(a,b), number of trapezoids N
	//and step size h
	float a, b, N, h;  
	//iterator
	int k; 
	
	// set initial conditions and tolerance level
	tol = 1E-6;
	a = 0.0;
	b = 1.0;
	N = 1;
	//initial guess at integral solution
	I1 = Trapezoid(a,b,N);
	I2 = 0.0;

	while(fabs(I1 - I2)/3.0 > tol) {
		//increase number of trapezoids by factor 2
		N *= 2;
		h = fabs(a-b)/N;
		
		//calculate the integral at odd values 
		//where initial estimate neglected, then add this to the half the 
		//initial estimate to obtain a new, more accurate, estimate of the integral
		for(k = 1; k < N; k += 2)
			I2 += h*f(a + k*h);
		I2 += I1/2;
		
		if(fabs(I1 - I2)/3.0 < tol) {
			printf("%f : %f,   %f : %f\n",N,I2,N/2.0,I1);
			break;
		}
		else {
			printf("%f : %f,   %f : %f,  err : %f\n",N,I2,N/2.0,I1,fabs(I1-I2)/3.0);
			I1 = I2;
			I2 = 0.0;
		}
	}
	
	return 0;
}


float f(float x) {
	
	return sin(sqrt(100*x))*sin(sqrt(100*x));
}

float Trapezoid(float a, float b, float N) {
	
	float h, Trap;
	int k;
	
	h = fabs(a-b)/N;
	Trap = 0.5*(f(a) + f(b));
	
	for(k = 1; k < N; k++)
		Trap += f(a + k*h);
	
	return Trap;
}

	