//Author: Stefan Toman

#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
        long n, p;
		cin >> n >> p;
		long b[n];
		for (long j = 0; j < n; j++) {
			cin >> b[j];
		}
		long long r = 0;
		long right = -1, sum = 0;
		for (long left = 0; left < n && right < n; left++) {
			while(right+1 < n && sum + b[right+1] <= p) {
				sum += b[right+1];
				right++;
			}
			r += right - left + 1;
			sum -= b[left];
		}
		cout << "Case #" << i+1 << ": " << r << endl;
	}
	return 0;
}
