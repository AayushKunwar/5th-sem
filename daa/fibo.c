#include<stdio.h>

int main(){
	int n = 10;
	int first = 1;
	int second = 2;
	int step = 0;
	// 0 and 1 first ma print garne
	printf("0 1 ");
	for(int i=2; i<n; i++){
		step++;
		printf("%d ",first);
		int third = first + second;
		first = second;
		second = third;
	}
	printf("\n Step = %d\n",step);
}
