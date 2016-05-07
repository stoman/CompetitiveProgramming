//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

int MAX = 2000000000;

long long powder(long long c, int n, vector<int> a, vector<int> b) {
	long long r = 0;
	for(int i = 0; i < n; i++) {
		if(c*a[i] > b[i] && r < MAX) r += c*a[i] - b[i];
	}
	return r;
}

int main() {
	int n;
	long long k;
	vector<int> a, b;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		b.push_back(t);
	}

	long long lo = 0, hi = MAX;
	while(hi - lo > 1) {
		long long mid = (hi + lo)/2;
		if(k < powder(mid, n, a, b)) hi = mid;
		else lo = mid;
	}
	
	cout << (k < powder(hi, n, a, b) ? lo : hi) << endl;

	return 0;
}

