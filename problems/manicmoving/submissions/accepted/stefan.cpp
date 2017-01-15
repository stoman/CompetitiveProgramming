//Author: Stefan Toman

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		//read roads
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<long long>> dist(n, vector<long long>(n, -1));
		for(int j = 0; j < m; j++) {
			int a, b, g;
			cin >> a >> b >> g;
			a--; b--;
			if(dist[a][b] == -1 || dist[a][b] > g) dist[a][b] = g;
			if(dist[b][a] == -1 || dist[b][a] > g) dist[b][a] = g;
		}
		for(int j = 0; j < n; j++) dist[j][j] = 0;
		//floyd warshall
		for(int j = 0; j < n; j++) {
			for(int a = 0; a < n; a++) {
				for(int b = 0; b < n; b++) {
					if(dist[a][j] != -1 && dist[j][b] != -1) {
						if(dist[a][b] == -1 || dist[a][b] > dist[a][j] + dist[j][b]) {
							dist[a][b] = dist[a][j] + dist[j][b];
						}
					}
				}
			}
		}
		/*for(int a = 0; a < n; a++) {
			for(int b = 0; b < n; b++) {
				cout << dist[a][b] << " ";
			}
			cout << endl;
		}*/
		//read customers
		vector<int> s(k), d(k);
		for(int j = 0; j < k; j++) cin >> s[j] >> d[j], s[j]--, d[j]--;
		//compute distances
		unordered_map<int, unordered_map<int, unordered_map<int, long long>>> memo;
		queue<tuple<int, int, int>> q;
		q.push(make_tuple(0, 0, 0));
		memo[0][0][0] = 0;
		while(!q.empty()) {
			//cout << "a" << endl;
			tuple<int, int, int> t = q.front();
			//cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << ": " << memo[get<0>(t)][get<1>(t)][get<2>(t)] << endl;
			q.pop();
			//load
			//cout << "b" << endl;
			if(get<0>(t) - get<1>(t) <= 1 && get<0>(t) < k && dist[get<2>(t)][s[get<0>(t)]] != -1) {
				//cout << "c" << endl;
				long long cost = memo[get<0>(t)][get<1>(t)][get<2>(t)] + dist[get<2>(t)][s[get<0>(t)]];
				if(memo[get<0>(t) + 1][get<1>(t)].find(s[get<0>(t)]) == memo[get<0>(t) + 1][get<1>(t)].end() || memo[get<0>(t) + 1][get<1>(t)][s[get<0>(t)]] > cost) {
					memo[get<0>(t) + 1][get<1>(t)][s[get<0>(t)]] = cost;
					q.push(make_tuple(get<0>(t) + 1, get<1>(t), s[get<0>(t)]));
				}
			}
			//unload
			//cout << "d" << endl;
			if(get<0>(t) - get<1>(t) >= 1 && dist[get<2>(t)][d[get<1>(t)]] != -1) {
				//cout << "e" << endl;
				long long cost = memo[get<0>(t)][get<1>(t)][get<2>(t)] + dist[get<2>(t)][d[get<1>(t)]];
				if(memo[get<0>(t)][get<1>(t) + 1].find(d[get<1>(t)]) == memo[get<0>(t)][get<1>(t) + 1].end() || memo[get<0>(t)][get<1>(t) + 1][s[get<0>(t)]] > cost) {
					memo[get<0>(t)][get<1>(t) + 1][d[get<1>(t)]] = cost;
					q.push(make_tuple(get<0>(t), get<1>(t) + 1, d[get<1>(t)]));
				}
			}
			//cout << "z" << endl;
		}
		cout << "Case #" << i << ": " << (memo[k][k].find(d[k-1]) == memo[k][k].end() ? -1 : memo[k][k][d[k-1]]) << endl;
	}
	return 0;
}

