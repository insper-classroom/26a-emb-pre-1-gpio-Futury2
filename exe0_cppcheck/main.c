#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}

int main(void) {
    int a =5;
    int b = 5; 
    int result = multiplyNumbers(a, b);

    printf("Resultado de %d * %d = %d\n", a, b, result);
    int arr[NUM_ELEMENTS];
    for(int i = 0; i < NUM_ELEMENTS; i++) { //arrayIndexOutOfBounds
        arr[i] = i;
    }
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
