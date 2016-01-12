//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n;
		scanf("%d", &n);
		long x[n], y[n];
		for (int j = 0; j < n; j++) {
			scanf("%ld %ld", &x[j], &y[j]);
		}
		long r = 0;
		for (int j = 0; j < n; j++) {
			map<long, long> dist;
			for (int k = 0; k < n; k++) {
				if(k != j) {
					long d = pow(x[j]-x[k], 2) + pow(y[j]-y[k], 2);
					dist[d]++;
				}
			}
			for(map<long, long>::iterator it = dist.begin(); it != dist.end(); ++it) {
				r += it->second*(it->second-1)/2;
			}
		}
		printf("Case #%d: %ld\n", i+1, r);
	}
	return 0;
}
