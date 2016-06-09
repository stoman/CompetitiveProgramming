//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> b(k, 0);
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		b[t % k]++;
	}
	int r = 0;
	if(b[0] > 0) r++;
	for(int i = 1; i <= k/2; i++) r += max(b[i], b[k-i]);
	cout << r << endl;
	return 0;
}

