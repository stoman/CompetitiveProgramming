//Author: Stefan Toman

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int r, c, ret = 0;
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		string row;
		cin >> row;
		if(i == r-1) {
			for(int j = 1; j < c; j++) if(row[j-1] == 'B' && row[j] == '.') ret++;
			if(row[c-1] == 'B') ret++;
		}
	}
	cout << ret << endl;
	return 0;
}

