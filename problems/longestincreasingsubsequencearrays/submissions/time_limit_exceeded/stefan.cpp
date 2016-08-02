//Author: Stefan Toman

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

const long long mod = 1000000007;

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
	
	int p;
	cin >> p;
	for(int j = 0; j < p; j++) {
		int m, n;
		cin >> m >> n;
		long long r = 1;
		for(int i = 1; i <= n; i++) r *= m-i+1, r %= mod, r *= inv(i, mod), r %= mod;
		for(int  i = 0; i < m-n; i++) r *= n-1, r %= mod;
		long long a = 1, npow = 1, n1pow = 1;
		for(int  i = 0; i < m-n; i++) npow *= n, npow %= mod, n1pow *= n-1, n1pow %= mod;
		for(int i = n; i < m; i++) {
			r += a * (npow - n1pow); r %= mod;
			a *= n-1; a %= mod;
			a *= i; a %= mod;
			a *= inv(i-n+1, mod); a %= mod;
			npow *= inv(n, mod); npow %= mod;
			n1pow *= inv(n-1, mod); n1pow %= mod;
		}
		while(r < 0) r += mod;
		cout << r << endl;
	}
	return 0;
}
