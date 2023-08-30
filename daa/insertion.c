#include<stdio.h>

int main(){
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	
	int comparisions = 0;
	
	for(int i=1; i<n; i++){
		int temp = a[i];
		int j = i-1;
		
		while(j >= 0){
			comparisions++;
			if(temp < a[j]){
				
				a[j+1] = a[j];
				j--;
			}
			else{
				break;
			}
		}
		a[j+1] = temp;
	}
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\nComparisions = %d\n",comparisions);
	return 0;
}
