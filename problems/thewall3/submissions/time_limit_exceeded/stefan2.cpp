//Author: Stefan Toman

#include <iostream>
#include <map>
#include <vector>

using namespace std;

const long long mod = 1000003;

map<int, long long> buffer;
void dp(int c, vector<long long>& count, int w) {
	buffer[0] = 1;
	for(int i = 1; i <= c; i++) {
		buffer[i] = buffer[i-1];
		for(int j = 1; j <= min(w, i); j++) {
			buffer[i] = (buffer[i] + count[j-1] * (i-j-1 <= 0 ? 1 : buffer[i-j-1])) % mod;
		}
	}
}

long long solve(int c, vector<long long>& count, int w) {
	if(buffer.count(c) > 0) return buffer[c];
	long long r;
	if(c < 0) {
		r = 0;
	}
	else {
		r = (solve(c/2, count, w) * solve((c-1)/2, count, w)) % mod;
		for(int l = 1; l <= w; l++) {
			for(int i = 0; i <= l-1; i++) {
				r = (r + count[l-1] * solve(c/2 - i - (c/2 - i == 0 ? 0 : 1), count, w) * solve((c-1)/2 - (l-i-1) - ((c-1)/2 - (l-i-1) == 0 ? 0 : 1), count, w)) % mod;
			}
		}
	}
	buffer[c] = r;
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	
	int c, w, h;
	cin >> c >> w >> h;
	vector<long long> count(w, h);
	for(int i = 1; i < w; i++) count[i] = (h*count[i-1]) % mod;
	dp(1000, count, w);
	cout << solve(c, count, w) << endl;
	return 0;
}
