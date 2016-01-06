//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        long n, a, b;
		scanf("%ld %ld %ld", &a, &b, &n);
        long r = a, twopow = 1;
        for (int j = 0; j < n; j++) {
            r += twopow * b;
            twopow *= 2;
            printf("%ld%s", r, j == n-1 ? "\n" : " ");
        }
	}
	return 0;
}
