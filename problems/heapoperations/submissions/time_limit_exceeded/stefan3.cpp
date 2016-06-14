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
	vector<string> r;
	
	for(int i = 0; i < n; i++) {
		string o;
		cin >> o;
		if(o[0] == 'i') {
			int x;
			cin >> x;
			q.push(x);
			r.push_back(o + " " + to_string(x));
		}
		else if(o[0] == 'r') {
			if(q.size() == 0) {
				q.push(1);
				r.push_back("insert 1");
			}
			q.pop();
			r.push_back(o);
		}
		else {
			int x;
			cin >> x;
			do {
				if(q.size() == 0 || q.top() > x) {
					q.push(x);
					r.push_back("insert " + to_string(x));
				}
				if(q.top() < x) {
					q.pop();
					r.push_back("removeMin");
				}				
				if(q.size() == 0 || q.top() > x) {
					q.push(x);
					r.push_back("insert " + to_string(x));
				}
			} while(q.top() != x);
			r.push_back(o + " " + to_string(x));
		}
	}
	cout << r.size() << endl;
	for(auto t: r) cout << t << endl;
	return 0;
}

