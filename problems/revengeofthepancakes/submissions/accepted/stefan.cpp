//Author: Stefan Toman

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
                string s;
                int r = 0;
		cin >> s;
		s.append("+");
		for(int j = 0; j < s.size() - 1; j++) {
		        if(s[j] != s[j+1]) r++;
		}
		
                cout << "Case #" << i << ": " << r << endl;
	}
	return 0;
}
