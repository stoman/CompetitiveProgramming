//Author: Stefan Toman

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n, r = 0;
	stringstream ss;
	cin >> n;
	priority_queue<int> q;
	for(int i = 0; i < n; i++) {
		string o;
		cin >> o;
		if(o == "insert") {
			int x;
			cin >> x;
			q.push(x);
			ss << o << " " << x << endl;
			r++;
		}
		else if(o == "removeMin") {
			if(q.size() == 0) {
				q.push(1);
				ss << "insert 1" << endl;
				r++;
			}
			q.pop();
			ss << o << endl;
			r++;
		}
		else {
			int x;
			cin >> x;
			do {
				if(q.size() == 0 || q.top() > x) {
					q.push(x);
					ss << "insert " << x << endl;
					r++;
				}
				if(q.top() < x) {
					q.pop();
					ss << "removeMin" << endl;
					r++;
				}				
			} while(q.top() != x);
			q.pop();
			ss << o << " " << x << endl;
			r++;
		}
	}
	cout << r << endl << ss.str();
	return 0;
}

