//Author: Stefan Toman

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, m;
		cin >> n >> m;
		vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
		dp[0][0] = 0;
		for(int j = 1; j <= n; j++) {
			vector<long long> prices(m);
			for(int k = 0; k < m; k++) cin >> prices[k];
			sort(prices.begin(), prices.end());
			for(int k = 0; k <= n; k++) {
				long long price = 0;
				for(int buy = 0; buy <= k+1 && buy <= m; buy++) {
					if(buy > 0) price += prices[buy - 1] + 2*(buy - 1) + 1;
					if(0 <= k - buy + 1 && k - buy + 1 <= n && dp[j-1][k - buy + 1] != -1) {
						if(dp[j][k] == -1 || dp[j][k] > dp[j-1][k - buy + 1] + price) {
							dp[j][k] = dp[j-1][k - buy + 1] + price;
						}
					}
				}
			}
		}
		cout << "Case #" << i << ": " << dp[n][0] << endl;
	}
	return 0;
}

