#include<stdio.h>

int step = 0;

int fact(int n){
	step++;
	if(n <= 1) return 1;
	return n * fact(n-1);
}

int main(){
	int n = 10;
	
	printf("The fact %d is %d\n",n,fact(n));
	printf("The steps is %d\n",step);
	return 0;
}
