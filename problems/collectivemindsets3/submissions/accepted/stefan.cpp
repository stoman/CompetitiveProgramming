//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int n, r, sum = 0;
		cin >> n >> r;
		for(int j = 0; j < n - 1; j++) {
			int temp;
			cin >> temp;
			sum += temp;
		}
		int ret = (r - sum) % n;
		while(ret <= 0) ret += n;
		cout << ret << endl;
	}
	return 0;
}
