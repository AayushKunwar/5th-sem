/* make sure only running in 64 bit
note to self ---
unsigned only required for convenience to print
unsigned long = 64 bits
unsigned int = 32 bits
1 hexadecimal value = 4 bits , write with 0x0FF...
*/

#include<stdio.h>

char r_key[16][8];

void generate_r_key(char pwd[]) {
    // numbered 1 to 64
    // 57 49 41 33 25 17 9
    // 1 58 50 42 34 26 18
    // 10 2 59 51 43 35 27
    // 19 11 3 60 52 44 36

}

int main() {
    char pwd[] = "cyka"; // max 64bits, i.e 8 characters
}