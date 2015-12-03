//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main() {
   int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		long long n;
		scanf("%lld", &n);
		int r = 0;
		long long tn = n;
		while (tn > 0) {
			if (tn % 10 > 0 && n % (tn % 10) == 0)
				r++;
			tn /= 10;
		}
		printf("%d\n", r);
	}
	return 0;
}
