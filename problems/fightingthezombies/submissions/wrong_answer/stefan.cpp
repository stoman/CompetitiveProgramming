//Author: Stefan Toman

//idea: the move operation corresponds to having a second square
//this operation can be set up in a way that no point originally in the square is moved out
//w.l.o.g. squares start at a point ~> O(n^3) algorithm

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, r;
		cin >> n >> r;
		vector<long long> x(n), y(n);
		for(int j = 0; j < n; j++) cin >> x[j] >> y[j];
		int best = 0;
		for(int s1 = 0; s1 < n; s1++) {
			for(int s2 = 0; s2 < n; s2++) {
				int current = 0;
				for(int j = 0; j < n; j++) {
					if((0 <= x[j] - x[s1] && x[j] - x[s1] <= r && 0 <= y[j] - y[s1] && y[j] - y[s1] <= r) || (0 <= x[j] - x[s2] && x[j] - x[s2] <= r && 0 <= y[j] - y[s2] && y[j] - y[s2] <= r)) current++;
				}
				if(current > best) best = current;
			}
		}

		cout << "Case #" << i << ": " << best << endl;
	}
	return 0;
}

