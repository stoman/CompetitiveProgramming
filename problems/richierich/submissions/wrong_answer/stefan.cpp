//Author: Stefan Toman

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<bool> changed(n, false);
	for(int i = 0; i < n/2; i++) {
		if(s[i] > s[n-1-i]) {
			s[n-1-i] = s[i];
			changed[n-1-i] = true;
			k--;
		}
		if(s[i] < s[n-1-i]) {
			s[i] = s[n-1-i];
			changed[i] = true;
			k--;
		}
	}
	if(k < 0) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n/2; i++) {
		int needed = (changed[i] ? 0 : 1) + (changed[n-1-i] ? 0 : 1);
		if(needed <= k) {
			k -= needed;
			s[i] = '9';
			s[n-1-i] = '9';
		}
	}
	if(n % 2 == 1 && k > 0) {
		s[n/2] = '9';
	}	
	cout << s << endl;
	return 0;
}

