#include<stdio.h>

int main() {
    int a = 161;
    int b = 28;

    while (b > 0) {
        int q = a / b;
        int r = a - q * b;
        a = b;
        b = r;
    }
    printf("%d", a);
    return 0;

}