//Author: Stefan Toman

#include <stdio.h>

int main() {
    int t = 40;
    printf("%d\n", t);
    for (int i = 0; i < t; i++) {
        long n = 100000, p = 1000000000;
        printf("%ld %ld\n", n, p);
        for (int i = 0; i < n; i++) {
            printf("%d%s", 1, i == n-1 ? "\n" : " ");
        }
    }
    return 0;
}