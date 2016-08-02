//Author: Stefan Toman

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		long long n, p, q;
		cin >> n >> p >> q;
		vector<long long> a(n);
		for(int j = 0; j< n; j++) cin >> a[j];
		sort(a.begin(), a.end());
		int r = 0;
		for(int j = 0; j< n; j++) {
			if(p+2*q >= a[j] && (a[j] % 2 == 0 || p > 0)) {
				int qq = min(q, a[j] / 2);
				q -= qq;
				p -= a[j] - 2*qq;
				r++;
			}
		}

		cout << r << endl;
	}
	return 0;
}

