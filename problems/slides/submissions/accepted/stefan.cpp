//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int b;
		long long m;
		cin >> b >> m;
		vector<int> r;
		bool ok = false;
		if(m == ((long long) 1 << b-2)) {
			for(int j = 0; j < b-1; j++) r.push_back(1);
			ok = true;
		}
		else {
			r.push_back(0);
			for(int j = 1; j < b-1; j++) {
				r.push_back(m % 2);
				m /= 2;
			}
			ok = m == 0;
		}
		cout << "Case #" << i+1 << ": " << (ok ? "" : "IM") << "POSSIBLE" << endl;
		if(ok) {
			for(int j = 0; j < b-1; j++) {
				for(int k = 0; k <= j; k++) cout << 0;
				for(int k = j+1; k < b-1; k++) cout << 1;
				cout << r[j];
				cout << endl;
			}
			for(int j = 0; j < b; j++) cout << 0;
			cout << endl;
		}
	}
	return 0;
}

