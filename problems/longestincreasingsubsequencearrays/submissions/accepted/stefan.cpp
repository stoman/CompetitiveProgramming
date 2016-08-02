//Author: Stefan Toman

#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000007;

long long inv(long long i) {
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

long long fastexp(long long a, long long b) {
	long long r = 1, e = a;
	while(b > 0) {
		if(b & 1) {
			r *= e;
			r %= mod;
		}
		b = b >> 1;
		e = (e * e) % mod;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);

	vector<long long> invs(500001);
	for(int i = 1; i < invs.size(); i++) invs[i] = inv(i);

	int p;
	cin >> p;
	for(int j = 0; j < p; j++) {
		int m, n;
		cin >> m >> n;
		long long r = 1, d = 1;
		for(int i = 1; i <= n; i++) r *= m-i+1, r %= mod, d *= i, d %= mod;
		r *= inv(d); r %= mod;
		r *= fastexp(n-1, m-n); r %= mod;
		long long a = 1, npow = fastexp(n, m-n), n1pow = fastexp(n-1, m-n);
		long long ninv = invs[n], n1inv = invs[n-1];
		for(int i = n; i < m; i++) {
			r += a * (npow - n1pow); r %= mod;
			a *= n-1; a %= mod;
			a *= i; a %= mod;
			a *= invs[i-n+1]; a %= mod;
			npow *= ninv; npow %= mod;
			n1pow *= n1inv; n1pow %= mod;
		}
		while(r < 0) r += mod;
		cout << r << endl;
	}
	return 0;
}
