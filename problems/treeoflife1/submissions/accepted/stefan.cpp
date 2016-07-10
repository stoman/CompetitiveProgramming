//Author: Stefan Toman

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	//input
	int n;
	cin >> n;
	vector<vector<int>> neighbours(n);
	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		neighbours[a-1].push_back(b-1);
		neighbours[b-1].push_back(a-1);
	}

	//count
	long long r = 0;
	for(int i = 0; i < n; i++) r += (neighbours[i].size() * (neighbours[i].size()-1))/2;

	//output
	cout << r << endl;
	return 0;
}

