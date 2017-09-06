#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N	50	//no. of lattice coordinates

int main(void)	{
	
	int i, j, k, sign;
	float M;
	
	M = 0;//madelung constant initially set to zero
	
	//nested for...loops to iterate over the lattice coords from the origin (0,0,0)
	for(i = -N; i < N; i++)	
		for(j = -N; j < N; j++)
			for(k = -N; k < N; k++)
				//skip the particle at the origin
				if((i==0) & (j==0) & (k==0))
					continue;
				//else calculate sign of electric potential and madelung const.
				else {
					if(abs(i+j+k)%2 == 0)
						sign = 1; //due to Na atom
					else
						sign = -1; //due to Cl atom 
					M += sign/sqrt(i*i + j*j + k*k);
				}
	
	//print value of the Madelung Constant 			
	printf("%f\n",M);
	
	return 0;
	
}