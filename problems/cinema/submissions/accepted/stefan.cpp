//Author: Stefan Toman

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n, m;
	map<int, int> a;
	vector<int> b, c;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a[t]++;
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		int t;
		cin >> t;
		b.push_back(t);
	}
	for(int i = 0; i < m; i++) {
		int t;
		cin >> t;
		c.push_back(t);
	}
	
	int r = 0;
	for(int i = 1; i < m; i++) {
		if(a[b[i]] > a[b[r]] || (a[b[i]] == a[b[r]] && a[c[i]] > a[c[r]])) {
			r = i;
		}
	}
	cout << r+1 << endl;

	return 0;
}

