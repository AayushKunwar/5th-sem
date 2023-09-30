// extended euclidean is used to find the
// the multiplicative inverse in mod N
#include<stdio.h>

int main() {
	// 11^-1 mod 26
	int dividor = 26;
	int r1 = dividor;
	int r2 = 11; // the this inverse to find
	int t1 = 0;
	int t2 = 1, q, t, r;
	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
		printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t \n", r1, r2, q, r, t1, t1, t);
	}
	if (r1 == 1) printf("The inverse is %d\n", (t1 + dividor) % dividor);
	else printf("not found :(");
	return 0;
}
