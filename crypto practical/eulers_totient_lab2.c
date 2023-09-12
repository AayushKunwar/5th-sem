#include<stdio.h>

int is_rel_prime(int a, int b) {
	for (int i = 2; i <= a && i <= b; i++) {
		if (a % i == 0 && b % i == 0) {

			return 0;
		}
	}
	return 1;
}

int main() {
	int num = 10;
	int counter = 0;
	printf("%d ->", num);
	for (int i = 1; i < num; i++) {
		if (is_rel_prime(i, num)) {
			printf(" %d,", i);
			counter++;
		}
	}
	printf("\nTotal: %d\n", counter);
	return 0;
}
