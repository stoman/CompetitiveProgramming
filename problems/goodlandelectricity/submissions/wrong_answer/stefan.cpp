//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	vector<int> tower(n+k-1, 0);
	for(int i = 0; i < n; i++) cin >> tower[i];
	int lastpossible = -k, lasttower = -k, r = 0;
	for(int i = 0; i < n; i++) {
		if(tower[i] == 1) lastpossible = i;
		if(lasttower + 2*(k-1) + 1 == i) {
			if(lastpossible == lasttower) {
				cout << -1 << endl;
				return 0;
			}
			else {
				lasttower = lastpossible;
				r++;
			}
		}
	}
	cout << r << endl;	
	return 0;
}

