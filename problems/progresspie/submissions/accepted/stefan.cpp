//Author: Stefan Toman

#include <cmath>
#include <iostream>

#define PI 3.14159265

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int p, x, y;
		cin >> p >> x >> y;
		x -= 50; y -= 50;
		bool incircle = x*x + y*y <= 50*50;
		double percentage = atan2(x, y) / PI / 2.0;
		if(percentage < 0) percentage += 1.0;
		bool angleok = percentage * 100.0 < p;
		cout << "Case #" << i << ": " << (incircle && angleok ? "black" : "white") << endl;
	}
	return 0;
}

