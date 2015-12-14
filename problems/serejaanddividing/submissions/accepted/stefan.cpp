//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        char a[1000000], b[10000];
        int l;
		scanf("%s\n%s\n%s", a, b, &l);

		printf("%s\n", a);
	}
	return 0;
}