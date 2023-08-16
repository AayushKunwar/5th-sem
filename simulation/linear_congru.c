#include<stdio.h>

int main(){
	int a,xi,c,m;
	printf("Enter the a, xi, c, m: ");
	scanf("%d%d%d%d",&a,&xi,&c,&m);
	
	if(c!= 0){
		printf("c != 0, i.e mixed congruential method\n");
	}
	else{
		printf("Multiplicative conguential method\n");
	}
	
	for(int i=0; i<10; i++){
		xi = (a*xi + c) % m;
		printf("x%d = %d = %f\n",i,xi, (float)xi/m);
	}
}
