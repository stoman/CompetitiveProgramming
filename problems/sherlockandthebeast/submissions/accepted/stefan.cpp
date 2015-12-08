//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n;
		scanf("%d", &n);
		int m = 0;
		while(n % 3 != 0) {
		    n -= 5;
		    m += 5;
		}
        if(n < 0) {
		    printf("-1\n");
        }
        else {
            for (int j = 0; j < n; j++) {
                printf("5");
            }
            for (int j = 0; j < m; j++) {
                printf("3");
            }
            printf("\n");
        }
	}
	return 0;
}
