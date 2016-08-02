//Author: Stefan Toman

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		unordered_set<char> chars;
		for(int i = 0; i < s.size(); i++) chars.insert(s[i]);
		cout << chars.size() << endl;
	}
	return 0;
}
