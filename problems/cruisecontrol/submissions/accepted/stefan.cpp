//Author: Stefan Toman

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		//read input
		long long d;
		int n;
		float t = -1;
		cin >> d >> n;
		for(int i = 0; i < n; i++) {
			long long k, s;
			cin >> k >> s;
			float r = 1.*(d-k)/s;
			if(r > t) t = r;
		}
		cout << "Case #" << i << ": " << fixed << setprecision(10) << d/t << endl;
	}
	return 0;
}

