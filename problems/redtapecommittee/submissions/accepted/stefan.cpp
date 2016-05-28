//Author: Stefan Toman

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		int n, k;
		cin >> n >> k;
		vector<long double> p(n);
		for(int i = 0; i < n; i++) cin >> p[i];
		sort(p.begin(), p.end());
		long double max = 0.0;
		for(int i = 0; i <= k; i++) {
			vector<vector<long double>> r(k+1, vector<long double>(k+1, 0.0));
			r[0][0] = 1.0;
			for(int j = 0; j < k; j++) {
				for(int l = 0; l <= j+1; l++) {
					r[j+1][l] += p[j + (j >= i ? n-k : 0)]*r[j][l];
					if(l > 0) r[j+1][l] += (1-p[j + (j >= i ? n-k : 0)])*r[j][l-1];
				}
			}
			if(max < r[k][k/2]) max = r[k][k/2];
		}
		cout << "Case #" << tt << ": " << fixed << setprecision(10) << max << endl;
	}
	return 0;
}

