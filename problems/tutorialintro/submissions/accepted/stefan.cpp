//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int v;
	scanf("%d", &v);
    int n;
    scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
        int a;
		scanf("%d", &a);
        if(a == v) {
		    printf("%d\n", i);
        	return 0;
        }
	}
}