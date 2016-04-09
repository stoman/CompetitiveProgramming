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
                int k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << i << ":";
		if(c*s < k) {
		        cout << " IMPOSSIBLE" << endl;
                }
                else {
                        for(int j = 0; j*c < k; j++) {
                                long long r = 1, p = 1;
                                for(int l = j*c; l < min((j+1)*c, k); l++) {
                                        r += p*l;
                                        p *= k;
                                }
                                cout << " " << r;
                        }
                        cout << endl;
                }
	}
	return 0;
}
