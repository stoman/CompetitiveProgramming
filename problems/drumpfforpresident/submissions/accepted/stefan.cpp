//Author: Stefan Toman

#include <vector>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		vector<int> votes(n, 0);
		vector<bool> self(n);
		for(int j = 0; j < n; j++) {
			int v;
			cin >> v;
			self[j] = v == j+1;
			votes[v-1]++;
		}

		int r = 0;
		for(int j = 0; j < n; j++) if(votes[j] >= k && !self[j]) r++;

		cout << r << endl;
	}
	return 0;
}

