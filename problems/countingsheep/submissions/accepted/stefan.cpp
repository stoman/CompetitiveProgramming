//Author: Stefan Toman

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
                long n;
		cin >> n;
		if(n == 0) {
		        cout << "Case #" << i << ": INSOMNIA" << endl;
		        continue;
		}
		int j = 0;
		vector<bool> seen (10, false);
		bool all;
		do {
		        j++;
        		int k = j*n;
        		while(k > 0) {
        		        seen[k%10] = true;
        		        k /= 10;
        		}
        		all = true;
        		for(int l = 0; l < 10; l++) all &= seen[l];
                }
                while(!all);

                cout << "Case #" << i << ": " << j*n << endl;
	}
	return 0;
}
