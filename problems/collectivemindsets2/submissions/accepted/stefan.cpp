//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int n, power = 1;
	cin >> n;
	while(power << 1 <= n) power = power << 1;
	cout << (n%2 == 0 ? n-power : n-1)/2 << endl;
	return 0;
}
