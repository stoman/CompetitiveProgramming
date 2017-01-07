//Author: Stefan Toman

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		vector<int> w(n);
		for(int j = 0; j < n; j++) cin >> w[j];
		sort(w.begin(), w.end());
		int r = 0, items = 0;
		for(int j = n-1; j >= 0 && items <= n; j--) {
			r++;
			items += 50/w[j] + (50 % w[j] == 0 ? 0 : 1);
		}
		if(items > n) r--;
		cout << "Case #" << i << ": " << r << endl;
	}
	return 0;
}

