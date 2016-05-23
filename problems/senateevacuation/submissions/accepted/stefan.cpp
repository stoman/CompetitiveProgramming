//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int p[n];
		int sum = 0;
		for(int j = 0; j < n; j++) {
			cin >> p[j];
			sum += p[j];
		}
		cout << "Case #" << i+1 << ":";
		while(true) {
			int max = -1;
			int maxb = -1;
			for(int j = 0; j < n; j++) {
				if((max == -1 && p[j] > 0) || (max > -1 && p[j] > p[max])) {
					max = j;
					maxb = -1;
				}
				else if(max > -1 && p[j] == p[max] && sum != 3) {
					maxb = j;
				}
			}
			if(max == -1) {
				break;
			}
			else {
				cout << " " << (char) ('A' + max);
				p[max]--;
				sum--;
				if(maxb > -1) {
					cout << (char) ('A' + maxb);
					p[maxb]--;
					sum--;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

