//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int x;
	double y;
	scanf("%d %lf", &x, &y);
	if(x + 0.5 <= y && x % 5 == 0) {
	    y -= x + 0.5;
	}
	printf("%.2f", y);
	return 0;
}
