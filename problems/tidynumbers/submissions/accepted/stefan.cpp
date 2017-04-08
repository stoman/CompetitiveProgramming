//Author: Stefan Toman

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		string s;
		cin >> s;
		int firstb = -1;
		for(int j = 0; j < s.size() - 1 && firstb == -1; j++) {
			if(s[j] > s[j+1]) firstb = j;
		}
		if(firstb >= 0) {
			s[firstb]--;
			for(int k = firstb + 1; k < s.size(); k++) s[k] = '9';
			for(int k = firstb - 1; k >= 0; k--) {
				if(s[k] > s[k+1]) {
					s[k]--;
					s[k+1] = '9';
				}
			}
			while(s[0] == '0') s.erase(0, 1);
		}
  	cout << "Case #" << i << ": " << s << endl;
	}
	return 0;
}

