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
		scanf("%d", &n);
		int r = 0, lastd = -1;
		for (int j = 0; j < n; j++) {
			int d;
			scanf("%d", &d);
			while(lastd != -1 && (j + r) % 4 != 0 && (d - lastd > 10 || d <= lastd)) {
				r++;
				lastd += 10;
			}
			lastd = d;
		}
		while((n + r) % 4 != 0) {
			r++;
		}

		printf("Case #%d: %d\n", i+1, r);
	}
	return 0;
}
