//Author: Stefan Toman

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	int n = s.length();
	long long r = 0;
	for(int i = n-1; i >= 0; i--) {
		int q = 0;
		if(s[i] == '0') {
			r++;
		}
		if((int)(s[i] - '0') % 2 == 0) {
			for(int j = i; j >= 0; j--) {
				q = (q + (int)(s[j] - '0')) % 3;
				if(s[j] != '0' && q == 0) r++;
			}
		}
	}
	cout << r << endl;
	return 0;
}
