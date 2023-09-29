/*
transistion matrix mat =
        Harvard Yale Dartmoth
Hardvard |   0.8     0.2     0.0  |
Yale     |   0.3     0.4     0.3|
Dartmoth |  0.2     0.1     0.7 |

initial matrix = [1, 0, 0]
*/
#include<stdio.h>

int main() {
    float mat[3][3] = { {0.8, 0.2, 0.0},
                        {0.3, 0.4, 0.3},
                        {0.2, 0.1, 0.7} };
    float x0[3] = { 1,0,0 };
    int size = 3;

    float result[3] = { 0 };
    for (int outer = 0; outer < 5; outer++) { // outer is the no of generations
        for (int i = 0; i < size; i++) { // this for matrix multiplication
            for (int j = 0; j < size; j++) {
                result[i] += x0[j] * mat[j][i];
            }
        }
        printf("Array x%d = ", outer + 1); // printing the result of current generation
        for (int i = 0; i < size; i++) {
            x0[i] = result[i];
            result[i] = 0;
            printf("%0.3f, ", x0[i]);
        }
        printf("\n");
    }
}