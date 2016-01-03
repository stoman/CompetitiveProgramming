//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int p[n];
	for (int j = 0; j < n; j++) {
		scanf("%d", &p[j]);
	}
	long r = 0;
	for (int j = n-1; j >= 0; j--) {
		for (int k = max(0, j-2); k < j; k++) {
			if(p[k] == j+1) {
				r++;
				int tt = p[k];
				p[k] = p[k+1];
				p[k+1] = tt;
			}
		}
		if(p[j] != j+1) {
			printf("Too chaotic\n");
			return;
		}
	}
	printf("%ld\n", r);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}
