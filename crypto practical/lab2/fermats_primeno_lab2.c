// generate prime numbers using fermats theorum
// upto LIMIT
#define LIMIT 1000

// works up 1000
// non-prime numbers accept fermat's theorum?

#include<stdio.h>
#include<math.h>

int is_prime(int num, int pri) {
    if (pri == 2 || pri == 3) return 1;
    if (pri == 5 || pri == 7) return 1;
    if (pri == 13) return 1;
    int num_copy = num;
    for (int power = 1; power < pri; power++) {
        num = (num * num_copy) % pri;
    }
    return num_copy == num;
}

int main() {
    int count = 0;
    for (int i = 2; i < LIMIT; i++) {
        int result1 = is_prime(3, i);
        int result2 = is_prime(2, i);
        int result3 = is_prime(13, i);

        if (result1 && result2 && result3) {
            printf("%d\n", i);
            count++;
        }
    }
    printf("Count = %d\n", count);
    return 0;
}
