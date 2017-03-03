//Author: Stefan Toman

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	int n = s.length();

	vector<vector<long long>> leftsum(n, vector<long long>(3, 0));
	for(int i = 1; i < n; i++) {
		int d = (int)(s[i-1] - '0');
		for(int j = 0; j < 3; j++) {
			leftsum[i][(j+d)%3] = leftsum[i-1][j];
		}
		if(d != 0) {
			leftsum[i][d%3]++;
		}
	}

	long long r = 0;
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == '0' || s[i] == '6') {
			r++;
		}
		int d = (int)(s[i] - '0');
		if(d % 2 == 0) {
			r += leftsum[i][(12 - d)%3];
		}
	}
	cout << r << endl;
	return 0;
}
