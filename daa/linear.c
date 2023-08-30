#include<stdio.h>

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(a)/sizeof(a[0]);
	int compr = 0;
	
	int n = 6;
	int found = -1;
	for(int i=0; i<size; i++){
		compr++;
		if(a[i] == n){
			found = i;
			break;
		}
	}
	if(found == -1){
		printf("Not found\n");
	}
	else{
		printf("Found at pos: %d\n",found+1);
	}
	printf("Compr = %d \n",compr);
	return 0;
}
