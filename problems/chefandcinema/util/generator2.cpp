//Author: Stefan Toman
//generate all medium inputs

#include <stdio.h>

int main() {
    printf("%d\n", 7*7*8*8*8*8);
    for (int n = 1; n <= 7; n++)
    for (int m = 1; m <= 7; m++)
    for (int z = 0; z <= 7; z++)
    for (int l = 0; l <= 7; l++)
    for (int r = 0; r <= 7; r++)
    for (int b = 0; b <= 7; b++)
    printf("%d %d %d %d %d %d\n", n, m, z, l, r, b);
}