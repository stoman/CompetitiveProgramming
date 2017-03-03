//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if(a == m) {
			m = b;
		}
		else if(b == m) {
			m = a;
		}
	}
	cout << m << endl;
	return 0;
}
