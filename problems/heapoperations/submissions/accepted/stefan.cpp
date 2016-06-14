//Author: Stefan Toman

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	priority_queue<int> q;
	vector<pair<string, int>> r;
	
	for(int i = 0; i < n; i++) {
		string o;
		cin >> o;
		if(o[0] == 'i') {
			int x;
			cin >> x;
			q.push(-x);
			r.push_back(make_pair(o, x));
		}
		else if(o[0] == 'r') {
			if(q.size() == 0) {
				q.push(-1);
				r.push_back(make_pair("insert", 1));
			}
			q.pop();
			r.push_back(make_pair(o, -1));
		}
		else {
			int x;
			cin >> x;
			do {
				if(q.size() == 0 || -q.top() > x) {
					q.push(-x);
					r.push_back(make_pair("insert ", x));
				}
				if(-q.top() < x) {
					q.pop();
					r.push_back(make_pair("removeMin", -1));
				}				
				if(q.size() == 0 || -q.top() > x) {
					q.push(-x);
					r.push_back(make_pair("insert ", x));
				}
			} while(-q.top() != x);
			r.push_back(make_pair(o, x));
		}
	}
	cout << r.size() << endl;
	for(auto t: r) if(t.first[0] == 'r') cout << t.first << endl; else cout << t.first << " " << t.second << endl;
	return 0;
}

