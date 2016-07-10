//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000003;

int main() {
	ios::sync_with_stdio(false);
	
	int c, w, h;
	cin >> c >> w >> h;
	vector<long long> count(w+1, 1);
	for(int i = 1; i <= w; i++) count[i] = (h*count[i-1]) % mod;
	vector<long long> r(w+2, 0);
	r[0] = 1;
	r[1] = 1;
	for(int i = 2; i <= c+1; i++) {
		r[i%(w+2)] = 0;
		for(int j = 0; j <= min(w, i-1); j++) {
			r[i%(w+2)] = (r[i%(w+2)] + count[j] * r[(i-j-1)%(w+2)]) % mod;
		}
	}
	cout << r[(c+1)%(w+2)] << endl;
	return 0;
}
