//Author: Stefan Toman

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	string b;
	cin >> b;
	vector<int> ma, l, r;
	int t = 0;
	stack<int> s;
	l.push_back(-1);
	r.push_back(1);
	ma.push_back(-1);
	for(int i = 0; i < n; i++) {
		l.push_back(i);
		r.push_back(i+2);
		ma.push_back(0);
		if(b[i] == '(') {
			s.push(i+1);
		}
		else {
			ma[i+1] = s.top();
			ma[s.top()] = i+1;
			s.pop();
		}
	}

	string a;
	cin >> a;
	for(int i = 0; i < m; i++) {
		if(a[i] == 'L') {
			p = l[p];
		}
		else if(a[i] == 'R') {
			p = r[p];
		}
		else {
			if(b[p-1] == '(') {
				int newp = r[ma[p]];
				if(newp == n+1) newp = l[p];
				r[l[p]] = r[ma[p]];
				if(r[ma[p]] <= n) l[r[ma[p]]] = l[p];
				p = newp;
			}
			else {
				int newp = r[p];
				if(newp == n+1) newp = l[ma[p]];
				l[r[p]] = l[ma[p]];
				r[l[ma[p]]] = r[p];
				p = newp;
			}
		}
	}

	p = r[0];
	while(p < n+1) {
		cout << b[p-1];
		p = r[p];
	}
	cout << endl;
	return 0;
}

