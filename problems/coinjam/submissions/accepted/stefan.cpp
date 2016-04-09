//Author: Stefan Toman

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
                int n, j;
		cin >> n >> j;
		cout << "Case #" << i << ": " << endl;
		for(int k = 0; k < j; k++) {
		        cout << "11";
		        int l = k;
		        for(int m = 0; m < (n-4)/2; m++) {
		                cout << l%2 << l%2;
		                l /= 2;
		        }
		        cout << "11";
		        for(int m = 2; m <= 10; m++) cout << " " << m+1;
		        cout << endl;
		}
	}
	return 0;
}
