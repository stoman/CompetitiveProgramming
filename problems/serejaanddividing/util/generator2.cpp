//Author: Stefan Toman
//generate medium input

#include <stdio.h>

int main() {
    int tt = 10;
    printf("%d\n", tt);
    for (int t = 0; t < tt; t++) {
        //a
        printf("1");
        for (int i = 1; i < 2000; i++) {
            printf("0");
        }
        printf("\n");
        //b
        printf("1");
        for (int i = 2; i < 2000; i++) {
            printf("0");
        }
        printf("\n");
        //l
        printf("2000\n");
    }
}
