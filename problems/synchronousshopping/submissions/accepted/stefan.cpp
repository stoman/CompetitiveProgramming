//Author: Stefan Toman

#include <climits>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(1, 0));
	vector<vector<pair<int, int>>> e(n);
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		for(int j = 0; j < t; j++) {
			int ta;
			cin >> ta;
			for(int old: a[i]) a[i].push_back(old | (1 << (ta-1)));
		}
	}
	for(int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x-1].push_back(make_pair(y-1, z));
		e[y-1].push_back(make_pair(x-1, z));
	}
	vector<vector<long long>> d(n, vector<long long>(1 << k, LLONG_MAX));
	queue<pair<int, int>> q;
	for(int ta: a[0]) {
		d[0][ta] = 0ll;
		q.push(make_pair(0, ta));
	}
	while(!q.empty()) {
		for(auto& te: e[q.front().first]) {
			for(int ta: a[te.first]) {
				if(d[te.first][q.front().second | ta] > d[q.front().first][q.front().second] + te.second) {
					d[te.first][q.front().second | ta] = d[q.front().first][q.front().second] + te.second;
					q.push(make_pair(te.first, q.front().second | ta));
				}
			}
		}
		q.pop();
	}
	long long r = LLONG_MAX;
	for(int i = 0; i < (1 << k); i++) {
		if(r > max(d[n-1][i], d[n-1][(1 << k) - 1 - i])) {
			r = max(d[n-1][i], d[n-1][(1 << k) - 1 - i]);
		}
	}
	cout << r << endl;
	return 0;
}

