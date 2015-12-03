//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main() {
   int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		long long r = 1;
		for (int j = 0; j < n/2; ++j) {
			r = 2*r+1;
		}
		printf("%d\n", n % 2 == 0 ? r : 2*r);
	}
	return 0;
}
