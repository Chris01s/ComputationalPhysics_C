#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#define PI	4*atan(1)

void f(float theta, float N){
	
	float x,y,t,dtheta;
	
	dtheta = theta/N;
	
	for(t = 0; t < theta; t += dtheta){
		x = 2*cos(t) + cos(2*t);
		y = 2*sin(t) - sin(2*t);
		printf("%f\t%f\n",x,y);
	}

	return;
}
	
void g(float theta, float N){
	
	float x,y,t,dtheta,r;
	
	dtheta = theta/N;
	
	for(t = 0; t < theta; t += dtheta){
		r = t*t;
		x = r*cos(t);
		y = r*sin(t);
		printf("%f\t%f\n",x,y);
	}
	
	return;
}
	
void h(float theta, float N){
	
	float x,y,r,t,dtheta;
	
	dtheta = theta/N;
	
	for(t = 0; t < theta; t += dtheta){
		r = exp(cos(t)) - 2*cos(4*t) + pow(sin(t/12),5);
		x = r*cos(t);
		y = r*sin(t);
		printf("%f\t%f\n",x,y);
	}
	
	return;
}

int main() {
	 
	char Graph;
	float theta,N;
	
	Graph = getch();
	
	if(Graph=='D'){
			theta = 2*PI;
			N = 1000;
			f(theta,N);
	}
	else if(Graph=='G'){
			theta = 10*PI;
			N = 2000;
			g(theta,N);
	}
	else if(Graph=='F'){
			theta = 24*PI;
			N = 2000;
			h(theta,N);
	}
	else
		printf("Choose D,G, or F\n");
	
	return 0;
}