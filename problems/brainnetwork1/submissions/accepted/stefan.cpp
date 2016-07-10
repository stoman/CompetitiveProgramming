//Author: Stefan Toman

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;

	if(m != n-1) {
		cout << "no" << endl;
		return 0;
	}

	vector<vector<int>> neighbours(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		neighbours[a-1].push_back(b-1);
		neighbours[b-1].push_back(a-1);
	}
	vector<bool> seen(n, false);
	vector<int> parent(n);
	queue<int> q;
	int count = 1;
	seen[0] = true;
	q.push(0);
	while(!q.empty()) {
		for(int t: neighbours[q.front()]) {
			if(parent[q.front()] != t) {
				if(seen[t]) {
					cout << "no" << endl;
					return 0;
				}
				else {
					q.push(t);
					seen[t] = true;
					parent[t] = q.front();
					count++;
				}
			}
		}
		q.pop();
	}
	cout << (count == n ? "yes" : "no") << endl;
	return 0;
}

