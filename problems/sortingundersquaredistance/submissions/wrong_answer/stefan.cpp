//Author: Stefan Toman

//This submission ignores that there may be several identical IDs.

#include <iostream>
#include <string.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long d[n];
	unordered_map<long long, long long> inv;
	for (long long i = 0; i < n; ++i) {
		cin >> d[i];
		inv.insert({d[i], i});
	}
	sort(d, d+n);
	long long r = 0;
	
	long long width = 1;
	while (width < n) {
		width *= 2;
	}

	long long size[2 * width - 1];
	memset(size, 0, (2 * width - 1) * sizeof(long long));
	for (long long i = 0; i < n; i++) {
		long long t = width + i - 1;
		size[t]++;
		while (t > 0) {
			t = (t - 1) / 2;
			size[t]++;
		}
	}

	for (long long i = 0; i < n; i++) {
		long long t = width + inv.find(d[i])->second - 1;
		size[t]--;
		while (t > 0) {
			if (t % 2 == 0) {
				r += size[t - 1];
			}
			t = (t - 1) / 2;
			size[t]--;
		}
	}
	
	cout << r << endl;
	return 0;
}
