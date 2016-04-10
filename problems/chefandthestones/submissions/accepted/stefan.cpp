//Author: Stefan Toman

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
        long long n1, n2, m;
		cin >> n1 >> n2 >> m;
		long long stones = m*(m+1)/2;
		cout << n1 + n2 - 2*min(min(n1, n2), stones) << endl;
	}
	return 0;
}
