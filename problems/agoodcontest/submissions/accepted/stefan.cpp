//Author: Stefan Toman

#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool ok = false;
	for(int i = 0; i < n; i++) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if(!ok && a >= 2400 && b > a) ok = true;
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}

