//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool ok = false;
	for(int a = 0; a <= n; a += 1234567) {
		for(int b = 0; b <= n-a; b += 123456) {
			if((n-a-b)%1234 == 0) {
				ok = true;
			}
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}

