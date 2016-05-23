//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		if(k == 0) {
			for(int j = 0; j < n; j++) cout << j+1 << " ";
			cout << endl;
		}
		else if(n % (2*k) != 0) {
			cout << -1 << endl;
		}
		else {
			for(int j = 0; j < n/(2*k); j++) {
				for(int l = 0; l < k; l++) cout << (j*2+1)*k+l+1 << " ";
				for(int l = 0; l < k; l++) cout << j*2*k+l+1 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

