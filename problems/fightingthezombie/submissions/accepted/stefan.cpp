//Author: Stefan Toman

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int h, s;
		cin >> h >> s;
		double max = 0.0;
		for(int j = 0; j < s; j++) {
			string str;
			cin >> str;
			int offset = 0;
			if(str.find('+') != string::npos) {
				offset = stoi(str.substr(str.find('+')+1, string::npos));
				str = str.substr(0, str.find('+'));
			}
			if(str.find('-') != string::npos) {
				offset = -stoi(str.substr(str.find('-')+1, string::npos));
				str = str.substr(0, str.find('-'));
			}
			int count = stoi(str.substr(0, str.find('d')));
			int sides = stoi(str.substr(str.find('d')+1, string::npos));
			vector<vector<double>> prob(count + 1, vector<double>(count * sides + 1));
			prob[0][0] = 1.0;
			for(int j = 1; j <= count; j++) {
				for(int before = 0; before <= (count-1)*sides; before++) {
					for(int roll = 1; roll <= sides; roll++) {
						prob[j][before + roll] += prob[j-1][before] / sides;
					}
				}
			}
			double total = 0;
			for(int j = h - offset >= 0 ? h - offset : 0; j <= count*sides; j++) {
				total += prob[count][j];
			}
			if(total > max) {
				max = total;
			}
		}
		cout << "Case #" << i << ": " << fixed << setprecision(16) << max << endl;
	}
	return 0;
}
