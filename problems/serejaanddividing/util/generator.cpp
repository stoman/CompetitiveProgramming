//Author: Stefan Toman
//generate maximum input

#include <stdio.h>

int main() {
    int tt = 1;
    printf("%d\n", tt);
    for (int t = 0; t < tt; t++) {
        //a
        printf("1");
        for (int i = 1; i < 1000000; i++) {
            printf("0");
        }
        printf("\n");
        //b
        printf("1");
        for (int i = 1; i < 10000; i++) {
            printf("0");
        }
        printf("\n");
        //l
        printf("10000\n");
    }
}
