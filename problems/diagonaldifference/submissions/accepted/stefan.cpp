//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int n, a = 0, b = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			if(i == j) a += t;
			if(i + j == n-1) b += t;
		}
	}
	printf("%d", abs(a-b));
}
