//Author: Stefan Toman

//Sorting the numbers needs to be done in O(n log n) instead of O(n^2).

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	long long d[n];
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &d[i]);
	}
	long long r = 0;
	bool change = true;
	while(change) {
		change = false;
		for (int i = 0; i < n-1; i++) {
			if(d[i] > d[i+1]) {
				long long t = d[i];
				d[i] = d[i+1];
				d[i+1] = t;
				r++;
				change = true;
			}
		}
	}
	
	printf("%lld", r);
	return 0;
}
