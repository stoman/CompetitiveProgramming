//Author: Stefan Toman

#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		//input
		int n, q;
		cin >> n >> q;
		vector<long long> e(n);
		vector<int> s(n);
		for(int j = 0; j < n; j++) cin >> e[j] >> s[j];
		vector<vector<long long>> d(n, vector<long long>(n));
		for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) cin >> d[j][k];

		//actual distances
		vector<vector<long long>> dd(n, vector<long long>(n, -1));
		for(int j = 0; j < n; j++) {
			priority_queue<pair<long long, int>> q;
			q.push(make_pair(e[j], j));
			while(!q.empty()) {
				pair<long long, int> p = q.top();
				q.pop();
				if(dd[j][p.second] == -1 || dd[j][p.second] > e[j] - p.first) {
					dd[j][p.second] = e[j] - p.first;
					for(int k = 0; k < n; k++) {
						if(d[p.second][k] != -1 && p.first - d[p.second][k] >= 0) {
							q.push(make_pair(p.first - d[p.second][k], k));
						}
					}
				}
			}

			/*for(int k = 0; k < n; k++) {
				cout << dd[j][k] << " ";
			}
			cout << endl;*/
		}
	

		//queries
		cout << "Case #" << i << ":";
		for(int j = 0; j < q; j++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			vector<double> td(n, -1.);
			priority_queue<pair<double, int>> q;
			q.push(make_pair(0., u));
			while(!q.empty()) {
				pair<double, int> p = q.top();
				q.pop();

				//cout << "t " << p.first << " " << p.second << endl;

				if(td[p.second] == -1. || td[p.second] > -p.first) {
					td[p.second] = -p.first;
					for(int k = 0; k < n; k++) {
						if(dd[p.second][k] != -1) {
							q.push(make_pair(p.first - 1. * dd[p.second][k] / s[p.second], k));
						}
					}
				}
			}

			cout << " " << fixed << setprecision(10) << td[v];

			/*cout << endl;
			for(int j = 0; j < n; j++) {
				cout << td[j] << " ";
			}
			cout << endl;*/
		}
		cout << endl;
	}
	return 0;
}

