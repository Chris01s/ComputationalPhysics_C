#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)	{
	
	int a[4] = {1,2,3,4};
	int b[4] = {2,4,6,8};
	int i, length;
	
	length = sizeof(a)/sizeof(int);
	
	for(i = 0; i < length; i++)	
		printf("%d\t%d\t%d\t%d\n",b[i]/a[i]+1,b[i]/(a[i]+1),1/a[i], length);
	
	return 0;
	
}

