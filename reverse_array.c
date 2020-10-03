#include<stdio.h>

void xor_swap(int *x, int *y) {
    *y = *x ^ *y;
    //printf("%d %d\n", *x, *y);
    *x = *x ^ *y;
    //printf("%d %d\n", *x, *y);
    *y = *x ^ *y;
    //printf("%d %d\n", *x, *y);
}

void reverse_array(int a[], int len) {
    int left, right = len - 1;
    for (left = 0; left < right; left++, right--) {
        xor_swap(&a[left], &a[right]);
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[4] = {1, 2, 3, 4};
    int b[5] = {1, 2, 3, 4, 5};
    reverse_array(a, 4);
    reverse_array(b, 5);

    return 0;
}
