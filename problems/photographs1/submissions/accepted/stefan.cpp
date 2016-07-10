//Author: Stefan Toman

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	//input
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int h, w;
		cin >> h >> w;
		vector<vector<int>> data(w, vector<int>(h));
		vector<long long> diff(h, 0);
		for(int y = 0; y < h; y++) {
			for(int x = 0; x < w; x++) {
				cin >> data[x][y];
				if(y > 0) diff[y] += pow(data[x][y] - data[x][y-1], 2);
			}
		}
		int bigger = -1;//remove the line itself
		for(int y = 0; y < h; y++) {
			if(diff[y] > diff[h/2]) bigger++;
		}
		cout << (bigger < max(1, h/20) ? "YES" : "NO") << endl;
	}
	return 0;
}

