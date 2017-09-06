#include <math.h>
#include <stdio.h>

int main(void)	{

	float C,n;
	
	//initial conditions
	C = 1;
	n = 0;
	
	while(C < 1E6)	{
		C *= (4*n + 2)/(n+2);
		n ++;
		printf("%d\n", (int)C);
	}
	return 0;
}