#include<stdio.h>

int subOK(int x, int y) {
    int diff = x + ~y + 1;
    int x_neg = x >> 31;
    int y_neg = y >> 31;
    int d_neg = diff >> 31;
    
    return !(~(x_neg ^ ~y_neg) & (x_neg ^ d_neg));
}

int main() {
    int n1 = subOK(0x80000000, 0x80000000);
    int n2 = subOK(0x80000000, 0x70000000);
    printf("%d\n", n1);
    printf("%d\n", n2);

    return 0;
}

