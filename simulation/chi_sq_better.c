#include<stdio.h>

#define EXP 10
#define MAX 20

int main(){
	float oi[] = {8,8,10,9,12,8,10,14,10,11};
	int size = sizeof oi / sizeof oi[0];

	int ei = EXP;

	float diff[MAX] = {0};
	for (int i=0; i<size; i++){
		
		diff[i] = (float)oi[i] - ei;
		//printf("%f\t", diff[i], oi[i], ei);
		diff[i] *= diff[i];
		//printf("%f \t", diff[i]);
		diff[i] = diff[i] / ei;
		//printf("%f \n", diff[i]);
	}

	// for the sum
	// couldv'e been done in the loop above
	float sum = 0;
	for(int i=0; i<size; i++){
		sum += diff[i];	
	}
	printf("The chi square is: %0.3f\n", sum);
	printf("The DF is %d\n", size-1);
	return 0;

}
