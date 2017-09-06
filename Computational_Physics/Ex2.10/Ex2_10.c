#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEN(x)		sizeof(x)/sizeof((x)[0])

float OddEvenZero(int A, int Z);
float BindingEnergy(int A,int Z);
void getBE_A(int Z, FILE *file1,FILE *file2);

int main(void) {

	int A = 58, Z = 28, i, Amax;
	float BE, Bmax;
	FILE *fout = fopen("BE_Nucleon.txt","w"), *fout2 = fopen("MAXBE_Nucleon.txt","w");
	FILE *fout3 = fopen("DummyFile.txt","w"), *fout4 = fopen("BE_NucleonCurve.txt","w");

	//a)
	BE = BindingEnergy(A,Z);
	printf("%f\n",BE);
	//b)
	printf("%f\n",BE/A);

	//c)
	getBE_A(Z,fout,fout2);
	fclose(fout);
	fclose(fout2);
	
	//d)
	for(Z = 1; Z < 101; Z++)
		getBE_A(Z,fout3,fout4);
		
	//close all files
	fclose(fout3);
	fclose(fout4);
	
	return 0;
	
}


float OddEvenZero(int A, int Z) {
	
	float a5;
	
	if(fmod(A,2) == 0) {
		if(fmod(Z,2) == 0)
			a5 = 12.0;
		else
			a5 = -12.0;
	}
	else
		a5 = 0.0;
	
	return a5;
}

float BindingEnergy(int A,int Z) {
	
	float a1,a2,a3,a4,a5,B;
	
	//Calculates and returns the BindingEnergy
	a1 = 15.67;
    a2 = 17.23;
    a3 = 0.75;
    a4 = 93.2;
    a5 = OddEvenZero(A,Z);
	B = (a1*A) - (a2*pow(A,2/3.0))- (Z*Z*a3/pow(A,1/3.0)) - (a4/A*(A-2*Z)*(A-2*Z)) + (a5/sqrt(A));
	
	return B;
}

void getBE_A(int Z, FILE *file1, FILE *file2) {
	
	int A, Amax;
	float BE_A, Bmax;
	
	Bmax = -1e5;
	
	for(A = Z; A < 3*Z; A++) {
		//get BE per nucleon and write to file
		BE_A = BindingEnergy(A,Z)/A;
		fprintf(file1,"%f\t%d\n",BE_A,A);
		
		//get max Binding Energy
		if(Bmax < BE_A){
			Bmax = BE_A;
			Amax = A;
		}
	}
	
	//write the max BE per nucleon to file
	fprintf(file2,"%f\t%d\n",Bmax,Amax);
	
	return;
}
