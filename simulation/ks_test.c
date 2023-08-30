#include<stdio.h>

#define MAX 20

void swap(float *a, float *b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(float *arra, int size){
	for(int i=0; i<size-1; i++){
		for(int j=0; j<size-i-1; j++){
			if(arra[j] > arra[j+1]){
				swap(&arra[j], &arra[j+1]);
			}
		}
	}
}

void print_arra(float *arra, int size){
	for(int i=0; i<size; i++){
		printf("%f \t", arra[i]);
	}
	printf("--\n");
}

int main(){
	// you can put this in any order
	float ri[] = {0.05, 0.44, 0.81, 0.93, 0.14};
	int size = sizeof ri / sizeof ri[0];
	//print_arra(ri,size);
	bubble(ri, size); // bubble sort 
	print_arra(ri, size);
	float d_plus[MAX] = {0};
	float d_plus_max = -100000;
	// d_plus nikalne
	for(int i=0; i<size; i++){
		d_plus[i] = i+1;
		d_plus[i] /= size;
		d_plus[i] = d_plus[i] - ri[i];
		//printf("%f \t", d_plus[i]);
		// find the d_plus_max here
		if(d_plus[i] > d_plus_max){
			d_plus_max = d_plus[i];
		}
	}	
	printf("%f is the d+\n", d_plus_max);
	float d_minus[MAX] = {0};
	float d_minus_max = -100000;
	// d_minus nikalne
	for(int i=0; i<size; i++){
		d_minus[i] = (float)i/size;
		
		d_minus[i] = ri[i] - d_minus[i];
	//	printf("%f \t", d_minus[i]);
		// find the d_plus_max here
		if(d_minus[i] > d_minus_max){
			d_minus_max = d_minus[i];
		}
	}	
	printf("%f is the d+\n", d_minus_max);
	
	d_plus_max = d_plus_max > d_minus_max ? d_plus_max : d_minus_max;
	
	printf("The D is %0.3f\n", d_plus_max);
	
}
