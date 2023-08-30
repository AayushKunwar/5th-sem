#include<stdio.h>

int main(){
	int n = 10;
	int fact = 1;
	int steps = 0;
	
	for(int i=1; i<=n; i++){
		fact *= i;
		steps++;
	}
	
	printf("Fact of %d is %d\n",n,fact);
	printf("Steps = %d\n",steps);
	return 0;
}
