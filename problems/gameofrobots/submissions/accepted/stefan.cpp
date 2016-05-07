//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	vector<int> id;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		id.push_back(t);
	}
	int c = 0;
	for(int i = 1; i <= n; i++) {
		if(c + i >= k) {
			cout << id[k - c - 1] << endl;
			return 0;
		}
		else {
			c += i;
		}
	}
	return 0;
}

