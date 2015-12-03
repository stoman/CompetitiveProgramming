//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int n, t;
	scanf("%d %d", &n, &t);
	int w[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w[i]);
	}
	for (int k = 0; k < t; ++k) {
		int max = 3, i, j;
		scanf("%d %d", &i, &j);
		for (int l = i; l <= j; ++l) {
			if(max > w[l]) max = w[l];
		}
		printf("%d\n", max);
	}
	return 0;
}
