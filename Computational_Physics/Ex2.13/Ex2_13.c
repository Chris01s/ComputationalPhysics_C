#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Catalan(int n) {
	
	if(n == 0)
		return 1;
	else
		return Catalan(n-1)*(4*n-2)/(n+1);
}

void Cat_num(int n) {
	
	int Cat,i;
	
	Cat = 1;
	for(i = 1; i < n; i++){
		Cat *= (4*i+2)/(float)(i+2);
		printf("%d\n",Cat);
	}
}

int g(int m,int n) {
	
	if(n==0)
		return m;
	else
		return g(n,fmod(m,n));
}


int main(void) {
	
	int n,m,Cats,commonDiv;
	
	n = 14;
	Cats = Catalan(n);
	printf("%d\n",Cats);
	
	Cat_num(n);
	
	n = 26;
	m = 58;
	commonDiv = g(m,n);
	printf("%d\n",commonDiv);
	
	return 0;
}
		
		