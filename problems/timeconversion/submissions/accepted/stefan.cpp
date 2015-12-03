//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char ampm[2];
    int h,m,s;
    scanf("%d:%d:%d%s", &h, &m, &s, ampm);
    if(h == 12) {
        h -= 12;
    }
    if(ampm[0] == 'P') {
        h += 12;
    }
    printf("%.2i:%.2i:%.2i", h, m, s);
    return 0;
}
