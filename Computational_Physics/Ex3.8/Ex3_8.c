#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	
	float x[10],y[10],m,c;
	float Ex, Ey, Exx, Exy;
	int n,i;
	
	Ex = 0.0;
	Ey = 0.0;
	Exx = 0.0;
	Exy = 0.0;
	n = 0;
	
	//READ IN FILE
	while(scanf("%f\t%f",&x[n],&y[n]) != EOF) {
		Ex += x[n];
		Ey += y[n];
		Exx += x[n]*x[n];
		Exy += x[n]*y[n];
		n++;
	}
	
	//Normalise
	Ex /= n;
	Ey /= n;
	Exx /= n;
	Exy /= n;
	//calculate gradient and intercept
	m = (Exy - Ex*Ey)/(Exx - Ex*Ex);
	c = (Exx*Ey - Ex*Exy)/(Exx - Ex*Ex);
	//printf("%e, %f",x[n-1],c);
	
	for(i = 0; i < n; i++)
		printf("%f\t%f\n",x[i],m*x[i] + c);
		 
	return 0;
}

	
	
	
	