//Author: Stefan Toman

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	//input
	int n, m;
	cin >> n >> m;
	vector<vector<int>> neighbours(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		neighbours[a-1].push_back(b-1);
		neighbours[b-1].push_back(a-1);
	}

	//first run
	vector<int> dist1(n, -1);
	queue<int> q;
	q.push(0);
	dist1[0] = 0;
	int maxdist = 0;
	while(!q.empty()) {
		for(int t: neighbours[q.front()]) {
			if(dist1[t] == -1) {
				q.push(t);
				dist1[t] = dist1[q.front()]+1;
				if(dist1[t] > dist1[maxdist]) maxdist = t;
			}
		}
		q.pop();
	}

	//second run
	vector<int> dist2(n, -1);
	dist2[maxdist] = 0;
	q.push(maxdist);
	while(!q.empty()) {
		for(int t: neighbours[q.front()]) {
			if(dist2[t] == -1) {
				q.push(t);
				dist2[t] = dist2[q.front()]+1;
				if(dist2[t] > dist2[maxdist]) maxdist = t;
			}
		}
		q.pop();
	}

	//output
	cout << dist2[maxdist] << endl;
	return 0;
}

