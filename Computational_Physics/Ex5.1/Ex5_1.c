#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

float dv(float v[], int i) {
	
	float s;
	int n;
	
	s += 0.5*(v[0] + v[-1]);
	
	for(n = 1; n < i; n++)
		s += v[n];
		
	return s;
}

void differentiate(float v[], float dist[], int i) {

	int n;
	
	dist[0] = 0.5*v[0];
	
	for(n = 1; n < i; n++) {
		dist[n] = ((v[n-1]+v[n])/2 + dist[n-1]);
		printf("%f\n",dist[n]);
	}
	
	return;
}


int main() {
	
	float t[150],v[150], s, dist[150];
	int i;
	
	//read in the file (to be redirected through batch/shell
	i = 0;
	while(scanf("%f\t%f",&t[i],&v[i]) != EOF)
		i++;

	//a)
	s = dv(v,i);
	
	differentiate(v,dist,i);
		
	return 0;
}