#include<stdio.h>

int main(){
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
//	int n =5;
	int comparisions = 0;
	int steps;
	int temp;
	for(int i=0; i<n-1; i++){
		int steps = 0;
		for(int j=0; j<n-i-1;  j++){
			comparisions++;
			if(a[j] > a[j+1]){
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				steps += 1;
			}
		}
		if(steps == 0){
			break;
		}
	}
	
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\nSteps = %d\n",steps);
	printf("Comparisions  = %d\n",comparisions);

	return 0;
}
