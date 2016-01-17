//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n;
        long a, b;
		scanf("%d %ld %ld", &n, &a, &b);
		long double e = 2*(b - a);
		long c[n];
		for (int j = 0; j < n; j++) {
			scanf("%ld", &c[j]);
		}
		long long r = 0;
		long time = 0;
		int cur = 0;
		while(b > 0) {
			if(a < c[cur]) {
				long long d = min(cur[c], b) - a;
				r += d*(2*a + d);
				a += d;
			}
			a -= c[cur];
			b -= c[cur];
			cur = (cur + 1) % n;
		}
		
		printf("Case #%d: %.9Lf\n", i+1, r / e);
	}
	return 0;
}
