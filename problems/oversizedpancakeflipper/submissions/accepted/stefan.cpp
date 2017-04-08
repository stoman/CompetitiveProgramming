//Author: Stefan Toman

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		//read input
		string s;
		int k;
		cin >> s >> k;
		vector<bool> b(s.size());
		for(int j = 0; j < s.size(); j++) b[j] = s[j] == '+';
		//compute return value
		int r = 0;
		for(int j = 0; j < s.size() - k + 1; j++) {
			if(!b[j]) {
				r++;
				for(int l = j; l < j + k; l++) b[l] = !b[l];
			}
		}
		bool ok = true;
		for(int j = 0; j < s.size(); j++) ok &= b[j];
		//print output
		if(ok) {
			cout << "Case #" << i << ": " << r << endl;
		}
		else {
			cout << "Case #" << i << ": IMPOSSIBLE" << endl;
		}
	}
	return 0;
}

