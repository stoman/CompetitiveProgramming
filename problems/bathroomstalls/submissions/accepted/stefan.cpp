//Author: Stefan Toman

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		long long n, k, j;
		cin >> n >> k;
		priority_queue<long long> q;
		q.push(n);
		unordered_map<long long, long long> m;
		m[n] = 1;
		while(k > 0) {
			j = q.top();
			q.pop();
			if(m[j] == 0) continue;
			k -= m[j];
			if(j % 2 == 1) {
				m[j/2] += 2*m[j];
				q.push(j/2);
				m[j] = 0;
			}
			else {
				m[j/2] += m[j];
				q.push(j/2);
				m[j/2-1] += m[j];
				q.push(j/2-1);
				m[j] = 0;
			}
		}
		cout << "Case #" << i << ": "<< (j-1)-(j-1)/2 << " " << (j-1)/2 << endl;
	}
	return 0;
}

