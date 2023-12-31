#include<stdio.h>

#define MAX 20

void swap(float* a, float* b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(float* arra, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arra[j] > arra[j + 1]) {
				swap(&arra[j], &arra[j + 1]);
			}
		}
	}
}

void print_arra(float* arra, int size) {
	for (int i = 0; i < size; i++) {
		printf("%0.3f \t", arra[i]);
	}
	printf("--\n");
}

int main() {
	// you can put this in any order
	float ri[] = { 0.05, 0.44, 0.81, 0.93, 0.14 };
	int size = sizeof ri / sizeof ri[0];
	bubble(ri, size); // bubble sort to put in ascending order
	printf("The array in rank is: \n");
	print_arra(ri, size);
	float d_plus, d_minus;
	float d_plus_max = -100000;
	float d_minus_max = -100000;

	// d_plus d_minus calculate 
	for (int i = 0; i < size; i++) {
		d_plus = ((float)(i + 1) / size) - ri[i];
		if (d_plus > d_plus_max) {
			d_plus_max = d_plus;
		}

		d_minus = ri[i] - ((float)i / size);
		if (d_minus > d_minus_max) {
			d_minus_max = d_minus;
		}
	}
	printf("%.3f is the d+\n", d_plus_max);

	printf("%.3f is the d+\n", d_minus_max);

	float d = d_plus_max > d_minus_max ? d_plus_max : d_minus_max;

	printf("The D is %0.3f\n", d);
	return 0;
}
