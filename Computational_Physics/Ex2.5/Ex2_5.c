#include <math.h>
#include <stdio.h>
#define	pi	4*atan(1)

int main(void)	{

	float eV,E,V,mass,hbar;
	float k1,k2,T,R;
	
	//Constants
	eV = 1.6E-19;
	E = 10*eV; //Particle energy
	V = 9*eV; //barrier height
	mass = 9.11E-31; //particle's mass
	hbar = 6.64E-34/(2*pi);

	//wavevectors
	k1 = sqrt(2*mass*E)/hbar;
	k2 = sqrt(2*mass*(E-V))/hbar;
	//Prbabilities
	T = 4*k1*k2/((k1+k2)*(k1+k2));
	R = ((k1-k2)*(k1-k2))/((k1+k2)*(k1+k2));

	printf("T = %f, R = %f", T,R);
	
	return 0;
}