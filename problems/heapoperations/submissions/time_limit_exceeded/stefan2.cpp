//Author: Stefan Toman

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, r = 0;
	string rr;
	cin >> n;
	priority_queue<int> q;
	for(int i = 0; i < n; i++) {
		string o;
		cin >> o;
		if(o[0] == 'i') {
			int x;
			cin >> x;
			q.push(x);
			rr += o + " " + to_string(x) + "\n";
			r++;
		}
		else if(o[0] == 'r') {
			if(q.size() == 0) {
				q.push(1);
				rr += "insert 1\n";
				r++;
			}
			q.pop();
			rr += o + "\n";
			r++;
		}
		else {
			int x;
			cin >> x;
			do {
				if(q.size() == 0 || q.top() > x) {
					q.push(x);
					rr += "insert " + to_string(x) + "\n";
					r++;
				}
				if(q.top() < x) {
					q.pop();
					rr += "removeMin\n";
					r++;
				}				
				if(q.size() == 0 || q.top() > x) {
					q.push(x);
					rr += "insert " + to_string(x) + "\n";
					r++;
				}
			} while(q.top() != x);
			rr += o + " " + to_string(x) + "\n";
			r++;
		}
	}
	cout << r << endl << rr;
	return 0;
}

