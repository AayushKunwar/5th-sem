#include<stdio.h>

#define EXP 10 // this the expected value
#define MAX 20

int main() {
	float oi[] = { 8, 8, 10, 9, 12, 8, 10, 14, 10, 11 };
	int count = sizeof oi / sizeof oi[0];

	int ei = EXP;

	float diff[MAX] = { 0 };
	float sum = 0;
	for (int i = 0; i < count; i++) {

		diff[i] = (float)oi[i] - ei;
		diff[i] *= diff[i];
		diff[i] = diff[i] / ei;
		sum += diff[i];
	}

	printf("The chi square is: %0.3f\n", sum);
	printf("The DF is %d\n", count - 1);
	return 0;

}
