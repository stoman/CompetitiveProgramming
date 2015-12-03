//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n,s=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        s += t;
    }
    printf("%d", s);
    return 0;
}
