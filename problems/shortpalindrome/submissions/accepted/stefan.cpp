//Author: Stefan Toman

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	long long r = 0;
	vector<vector<long long>> pairs(26, vector<long long>(26, 0)), half(26, vector<long long>(26, 0));
	vector<long long> chars(26, 0);
	for(int i = 0; i < s.size(); i++) {
		int c = s[i] - 'a';
		for(int j = 0; j < 26; j++) r += half[c][j], r %= mod;
		for(int j = 0; j < 26; j++) half[j][c] += pairs[j][c], half[j][c] %= mod;
		for(int j = 0; j < 26; j++) pairs[j][c] += chars[j], pairs[j][c] %= mod;
		chars[c]++;
	}
	cout << r << endl;
	return 0;
}
