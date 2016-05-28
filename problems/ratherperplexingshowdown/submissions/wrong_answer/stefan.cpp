//Author: Stefan Toman

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string compute(int n, int r, int p, int s) {
}

int main() {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		int n;
		vector<int> r(1), p(1), s(1), sum(1);
		cin >> n >> r[0] >> p[0] >> s[0];
		sum[0] = r[0] + p[0] + s[0];
		bool ok = true;
		for(int i = 1; i <= n; i++) {
			r.push_back((r[i-1] + s[i-1] - p[i-1])/2);
			p.push_back((p[i-1] + r[i-1] - s[i-1])/2);
			s.push_back((s[i-1] + p[i-1] - r[i-1])/2);
			sum.push_back(sum[i-1]/2);
			ok &= r[i] >= 0 && p[i] >= 0 && s[i] >= 0 && r[i] + p[i] + s[i] == sum[i];
		}
		if(!ok) {
			cout << "Case #" << tt << ": " << "IMPOSSIBLE" << endl;
		}
		else {
			//create
			vector<string> ret(n+1);
			if(r[n] == 1) ret[n] = "R";
			else if(p[n] == 1) ret[n] = "P";
			else if(s[n] == 1) ret[n] = "S";
			for(int i = n-1; i >= 0; i--) {
				ret[i] = "";
				for(int j = 0; j < sum[i+1]; j++) {
					if(ret[i+1][j] == 'R') ret[i] += "RS";
					else if(ret[i+1][j] == 'P') ret[i] += "RP";
					else if(ret[i+1][j] == 'S') ret[i] += "PS";
				}		
			}
			//sort
			for(int i = 1; i <= n; i++) {
				for(int j = 0; j < sum[i]; j+= sum[n-i]) {
					if(ret[0].substr(j, sum[n-i+1]) > ret[0].substr(j+sum[n-i+1], sum[n-i+1])) {
						string tmp = ret[0].substr(j+sum[n-i+1], sum[n-i+1]);
						ret[0].replace(j+sum[n-i+1], sum[n-i+1], ret[0].substr(j, sum[n-i+1]));
						ret[0].replace(j, sum[n-i+1], tmp);
					}
				}
			}
			cout << "Case #" << tt << ": " << ret[0] << endl;
		}
	}
	return 0;
}

