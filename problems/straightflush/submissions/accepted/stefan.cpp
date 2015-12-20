//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	//input
	char cards[5][2];
	for (int i = 0; i < 5; ++i) {
		scanf("%s", cards[i]);
	}
	
	//suit
	bool suit = true;
	for (int i = 0; i < 4; i++) {
		suit = suit && cards[i][1] == cards[i+1][1];
	}

	//straight
	char order[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	int longest = 0, current = 0;
	for (int i = 0; i < 14; i++) {
		bool found = false;
		for (int j = 0; j < 5; j++) {
			found = found || cards[j][0] == order[i];
		}
		if(found) {
			current++;
			longest = max(longest, current);
		}
		else {
			current = 0;
		}
	}

	printf("%s\n", suit && longest >= 5 ? "YES" : "NO");
	return 0;
}
