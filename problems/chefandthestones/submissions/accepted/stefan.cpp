//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        long long n1, n2, m;
		scanf("%I64d %I64d %I64d", &n1, &n2, &m);
		long long stones = m*(m+1)/2;
		printf("%I64d\n", n1 + n2 - 2*min(min(n1, n2), stones));
	}
	return 0;
}
