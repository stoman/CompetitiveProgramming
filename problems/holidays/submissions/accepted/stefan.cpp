//Author: Stefan Toman

#include <iostream>

using namespace std;

int work(int n) {
	return 2*(n/7) + (n%7==6 ? 1 : 0);
}

int main() {
	int n;
	cin >> n;
	cout << work(n) << " " << (n==1 ? 1 : 2+work(n-2)) << endl;
	return 0;
}

