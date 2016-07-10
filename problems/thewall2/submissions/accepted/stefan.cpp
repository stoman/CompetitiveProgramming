//Author: Stefan Toman

#include <iostream>
#include <string>

using namespace std;

const long long mod = 1000003;

long long inv(long long i, long long mod) {
	long long x = 0, y = 1, u = 1, v = 0, a = i, b = mod, q, r, m, n;
	while(a != 0) {
		q = b/a;
		r = b%a;
		m = x-u*q;
		n = y-v*q;
		b = a;
		a = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	
	int n, c;
	cin >> n >> c;
	long long r = 1;
	for(int  i = 0; i < c; i++) {
		r = (r*(n+c-i)) % mod;		
		r = (r*inv(i+1, mod)) % mod;
	}	
	r--;//use at least one stone
	while(r < 0) r += mod;
	cout << r << endl;
	return 0;
}
