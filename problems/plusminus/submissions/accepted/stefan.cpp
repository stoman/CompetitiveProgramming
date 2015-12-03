//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n,a=0,b=0,c=0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if(t > 0) {
            a++;
        }
        else if(t < 0) {
            b++;
        }
        else {
            c++;
        }
    }
    printf("%f\n%f\n%f\n", (double)a/n, (double)b/n, (double)c/n);
}
