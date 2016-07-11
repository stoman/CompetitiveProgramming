//Author: Stefan Toman and Philipp Hoffmann

#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000003;

int main() {
	ios::sync_with_stdio(false);
	
	int c, w, h;
	cin >> c >> w >> h;
	vector<long long> power(w+2, 1);
	for(int i = 1; i < w+2; i++) power[i] = (h*power[i-1]) % mod;
	
	vector<long long> dp(w+3);
	dp[0] = 0;
	dp[1] = h+1;
	for(int i = 2; i <= w + 1; i++) dp[i] = ((h+1)*dp[i-1]) % mod;
	dp[w+1] -= power[w+1];
	dp[w+2] = 0;
	for(int i = 0; i <= w; i++) dp[w+2] += power[i]*dp[w+1-i], dp[w+2] %= mod;
	for(int i = w+3; i <= c; i++) {
		dp[i%(w+3)] = (h*(dp[(i-1)%(w+3)] - power[w]*dp[(i-w-2)%(w+3)]) + dp[(i-1)%(w+3)]) % mod;
	}
	while(dp[c%(w+3)] < 0) dp[c%(w+3)] += mod;
	cout << dp[c%(w+3)] << endl;
	return 0;
}
