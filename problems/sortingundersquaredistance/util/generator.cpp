#include <stdio.h>

int main() {
    int n = 100000;
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d", 1000000000 - i);
        if(i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}