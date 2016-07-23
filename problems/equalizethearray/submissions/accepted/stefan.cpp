//Author: Stefan Toman

#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n, max = 0;
	map<int, int> counts;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		counts[t]++;
		if(counts[t] > max) max = counts[t];
	}
	cout << n - max << endl;
	return 0;
}
