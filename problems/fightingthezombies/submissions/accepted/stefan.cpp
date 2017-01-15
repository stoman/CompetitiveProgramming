//Author: Stefan Toman

//idea: the move operation corresponds to having a second square
//this operation can be set up in a way that no point originally in the square is moved out
//w.l.o.g. squares start left and top at a point ~> O(n^5) algorithm

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int n;
		long long r;
		cin >> n >> r;
		vector<long long> x(n), y(n);
		for(int j = 0; j < n; j++) cin >> x[j] >> y[j];
		int best = 0;
		for(int s1x = 0; s1x < n; s1x++) {
			for(int s2x = 0; s2x < n; s2x++) {
				for(int s1y = 0; s1y < n; s1y++) {
					for(int s2y = 0; s2y < n; s2y++) {
						int current = 0;
						for(int j = 0; j < n; j++) {
							if((0 <= x[j] - x[s1x] && x[j] - x[s1x] <= r && 0 <= y[j] - y[s1y] && y[j] - y[s1y] <= r) || (0 <= x[j] - x[s2x] && x[j] - x[s2x] <= r && 0 <= y[j] - y[s2y] && y[j] - y[s2y] <= r)) current++;
						}
						if(current > best) best = current;
					}
				}
			}
		}

		cout << "Case #" << i << ": " << best << endl;
	}
	return 0;
}

