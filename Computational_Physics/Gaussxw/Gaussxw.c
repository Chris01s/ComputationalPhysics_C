#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define pi	4*atan(1)

float max(float arr[],int N){
	/*This function obtains the maximum 
	value from the input array,arr*/
	int i;
	float maxValue;
	
	maxValue = 0.0;
	for(i = 0; i < N; i++){
		if(maxValue < fabs(arr[i]))
			maxValue = fabs(arr[i]);
		else
			continue;
	}
	
	return maxValue;
}

void repopulate(float p0[],float p1[],float x[],int N) {
	/*A function to repopulate (reinitialise) the vector of solutions to 
	the legendre polynomials that will then be used in the function below 
	to obtain the roots of the polynomial*/

	int n;
	
	for(n = 0; n < N; n++){
		p0[n] = 1;
		p1[n] = x[n];
	}
	
	return;
}

void getRoots(float p0[],float p1[],float x[],int N){

	/*This function calculates the roots of the polynomial recursively. 
	Its input is the two reinitialised guesses to the roots, p0, and p1
	along with the length of the array and the previous guesses of the roots x.*/ 
	
	float i,temp;
	int n;
	
	//This section uses Newton's Method to find all the roots
	for(i = 1; i < N; i++)
		for(n = 0; n < N; n++) {
			temp = p0[n];
			p0[n] = p1[n];
			p1[n] = ((2*i+1)*x[n]*p1[n]-i*temp)/(i+1);
		}

	return;
}

void gaussxw(int N,float x[N],float w[N]){

	/*The host function that calculates the roots of the function*/

	float a[N],p0[N],p1[N],dp[N],dx[N];
	float i,temp,alpha;
	float tol,delta;
	int n,step;
	
	step = 4;
	
	/*Set initial guess for the roots of the legendre polynomial
	as approximated by recurrence relation given in Abramowitz and Stegun
	22.7.10.*/
	for(i = 3,n = 0; i < 4*N; n++,i+=step) {
		a[n] = i/(4*N+2);
		x[n] = cos(pi*a[n]+1/(8*N*N*tan(a[n])));
	}
	
	
	tol = 1E-15;
	delta = 1.0;
	while(delta > tol) {
		
		repopulate(p0,p1,x,N);
		getRoots(p0,p1,x,N);//Newton's Method

		//Now the positions of the Gaussian can be calculated
		for(n = 0; n < N; n++) {
			dp[n] = (N+1)*(p0[n]-x[n]*p1[n])/(1-x[n]*x[n]);
			dx[n] = p1[n]/dp[n];
			x[n] -= dx[n];
		}
		
		//Pick the maximum difference to compare against the tolerance level
		delta = max(dx,N);
	}
	
	//Using our gaussian positions, get the weights
	for(n = 0; n < N; n++){
		w[n] = 2*(N+1)*(N+1)/(N*N*(1-x[n]*x[n])*dp[n]*dp[n]);
		printf("%f\t%f\n",w[n],x[n]);
	}

	return;
}
	
int main(void){
	
	int N;
	scanf("%d",&N);
	
	float x[N],w[N];
	gaussxw(N,x,w);
	
	return 0;
}
