//https://www.mathsisfun.com/data/chi-square-test.html

#include<stdio.h>
#include<math.h>
#define DIM 2

int main(){
	int obj[DIM][DIM] = {{207,282},{231,242}};
	float exp[DIM][DIM] = {0};
	long row_total[DIM] = {0};
	long col_total[DIM] = {0};
	long total = 0;
	float ci = 0;
	int df = (DIM-1)*(DIM-1);
	
	for(int i=0; i<DIM; i++){ // i is the row
		for(int j=0; j<DIM; j++){ // j is the col
			printf("%d \t",obj[i][j]);
			row_total[i] += obj[i][j];
			col_total[j] += obj[i][j];
		}
		printf("\n");
	}
	printf("-----\n");
	for(int i=0; i<DIM; i++){
		//printf("%d: col:%d row:%d\n",i,col_total[i], row_total[i]);
		total += row_total[i];
	}
	printf("Total: %d\n",total);
	for(int i=0; i<DIM; i++){
		for(int j=0; j<DIM; j++){
			exp[i][j] = (float) row_total[i] * col_total[j] / (float)total;
			printf("%f \t",exp[i][j]);
		}
		printf("\n");
	}
	printf("-----\n");
	for(int i=0; i<DIM; i++){
		for(int j=0; j<DIM; j++){
			exp[i][j] = (float)pow(obj[i][j] - exp[i][j],2) / exp[i][j];
			printf("%f \t",exp[i][j]);
			ci+=exp[i][j];
		}
		printf("\n");
	}
	printf("-----\n");
	printf("Ci-square: %f\n",ci);
	printf("Degree of freedom: %d\n",df);
	return 0;
	
}
