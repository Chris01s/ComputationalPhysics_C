#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NROWS	1000
#define NCOLS	2

void read_in_data(FILE *myfile, float array[NROWS][NCOLS]);

int main(void) {

	int i,j,r;
	float mov_avg,data[NROWS][NCOLS];
	FILE *fin = fopen("sunspots.txt","r");
	
	read_in_data(fin,data);
	r = 5;
	
	for(i = r; i < NROWS-r; i++){
		
		//initial value for the moving average
		mov_avg = 0;
		
		//Calculate the cumulative sum
		for(j = -r+i; j < r+i; j++)
			mov_avg += data[j][1];
		
		//Calculate the average from the cumulative sum
		//and print the result(to be redirected to file)
		mov_avg /= (2*r);
		printf("%f\t%f\n",mov_avg,data[i][0]);
	}
	
	return 0;
}



//function to read in the data: arg1 is file pointer name, arg2 is array to store data points
void read_in_data(FILE *myfile, float array[NROWS][NCOLS]){
	
	int i, j;
	
	//if data file is not in the directory, produce error message
	//else, read in the file then close
    if (myfile == NULL)
    	printf("Cannot open TEXT file\n");
    else{
		for (i = 0; i < NROWS; i++)
			for(j = 0; j < NCOLS; j++)
				fscanf(myfile, "%g", &array[i][j]);
		fclose(myfile);
	}
	
    return;
}