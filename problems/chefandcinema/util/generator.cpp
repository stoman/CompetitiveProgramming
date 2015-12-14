//Author: Stefan Toman
//generate all small inputs

#include <stdio.h>

int main() {
    printf("%d\n", 3*3*4*4*4*4);
    for (int n = 1; n <= 3; n++)
    for (int m = 1; m <= 3; m++)
    for (int z = 0; z <= 3; z++)
    for (int l = 0; l <= 3; l++)
    for (int r = 0; r <= 3; r++)
    for (int b = 0; b <= 3; b++)
    printf("%d %d %d %d %d %d\n", n, m, z, l, r, b);
}

