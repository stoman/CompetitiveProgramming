//Author: Stefan Toman

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	int r = 1;
	for(int i = 0; i < s.size(); i++) if(s[i] <= 'Z') r++;
	cout << r << endl;
	return 0;
}

