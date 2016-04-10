//Author: Stefan Toman

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
        int n;
		scanf("%d", &n);
		long long a[n];
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		int r = 0;
		for (int x = 0; x < n; x++) {
			long long sum = 0;
			long long product = 1;
			for (int y = x; y < n; y++) {
				sum += a[y];
				product *= a[y];
				if(sum == product) {
					r++;
				}
			}
		}
		cout << r << endl;
	}
	return 0;
}
