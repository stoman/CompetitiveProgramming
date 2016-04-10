//Author: Stefan Toman

//Sorting the numbers needs to be done in O(n log n) instead of O(n^2).

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long d[n];
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	long long r = 0;
	bool change = true;
	while(change) {
		change = false;
		for (int i = 0; i < n-1; i++) {
			if(d[i] > d[i+1]) {
				long long t = d[i];
				d[i] = d[i+1];
				d[i+1] = t;
				r++;
				change = true;
			}
		}
	}
	
	cout << r << endl;
	return 0;
}
