//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	int r = 0;
	for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) if((a[i] + a[j]) % k == 0) r++;
	cout << r << endl;
	return 0;
}

