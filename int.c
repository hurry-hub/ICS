#include<stdio.h>

int main() {
    unsigned int x = 134;
    unsigned int y = 246;
    int m = x;
    int n = y;
    unsigned int z1 = x - y;
    unsigned int z2 = x + y;
    int k1 = m - n;
    int k2 = m + n;
    printf("%d %d %d %d %d %d %d %d\n", x, y, m, n, z1, z2, k1, k2);

    return 0;
}