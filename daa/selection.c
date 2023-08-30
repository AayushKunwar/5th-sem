#include<stdio.h>

int main(){
	int a[] = {2,34,1,7,3,8};
	int n = sizeof(a)/sizeof(a[0]);
	
	int steps;
	int comparisions = 0;
	
	for(int i=0; i<n-1; i++){
		int min = i;
		
		for(int j=i+1; j<n; j++){
			comparisions++;
			if(a[min] > a[j]){
				min = j;
				
			}
		}
		if(min != i){
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			steps++;
		}
	}
	
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\nSteps = %d\n",steps);
	printf("Comparisions  = %d\n",comparisions);
	return 0;
}
