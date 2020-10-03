#include<stdio.h>

void xor_swap(int *x, int *y) {
    *y = *x ^ *y;
    printf("%d %d\n", *x, *y);
    *x = *x ^ *y;
    printf("%d %d\n", *x, *y);
    *y = *x ^ *y;
    printf("%d %d\n", *x, *y);
}

int main() {
    int a = 1;
    int b = 2;
    xor_swap(&a, &b);

    return 0;
}
