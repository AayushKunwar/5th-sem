// to calculate b^n mod m

#include<stdio.h>
#include<math.h>

int main() {
    long b = 64;
    int n = 72;
    int m = 13;

    int b_copy = b;

    while (n - 1) {
        b = (b * b_copy) % m;
        // printf("%d\n", b);
        n--;
    }
    printf("%d", b);
}