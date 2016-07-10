//Author: Stefan Toman

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool between(int a, int b, int c) {
	return a <= b && b <= c;
}

int main() {
	ios::sync_with_stdio(false);
	
	//input
	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n));
	for(int i = n-1; i >= 0; i--) {
		string row;
		cin >> row;
		for(int j = 0; j < n; j++) m[j][i] = row[j] - '0';
	}

	//lair location
	int minx = -9, miny = -9, maxx = -9, maxy = -9;
	int x = 0, y = 0;
	while(minx == -9) {
		if(m[x][y] != 0) {
			minx = x;
			miny = y;
			if(m[x][y] > 1 && x == 0) minx--;
			if(m[x][y] > 1 && y == 0) miny--;
		}
		x++;
		if(x >= n) {
			x = 0;
			y++;
		}
		if(y >= n) {
			cout << "No" << endl;
			return 0;
		}
	}
	x = n-1; y = n-1;
	while(maxx == -9) {
		if(m[x][y] != 0) {
			maxx = x;
			maxy = y;
			if(m[x][y] > 1 && x == n-1) maxx++;
			if(m[x][y] > 1 && y == n-1) maxy++;
		}
		x--;
		if(x < 0) {
			x = n-1;
			y--;
		}
		if(y < 0) {
			cout << "No" << endl;
			return 0;		
		}
	}

	//check
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int should = 0;
			if(between(minx, i, maxx-1) && between(miny, j, maxy-1)) should++;
			if(between(minx, i, maxx-1) && between(miny+1, j, maxy)) should++;
			if(between(minx+1, i, maxx) && between(miny, j, maxy-1)) should++;
			if(between(minx+1, i, maxx) && between(miny+1, j, maxy)) should++;
			if(m[i][j] != should) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}

