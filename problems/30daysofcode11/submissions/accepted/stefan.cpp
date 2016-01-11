//Author: Stefan Toman

#include <stdio.h>

using namespace std;

int main() {
    int n[36], hourglass[] = {0, 1, 2, 7, 12, 13, 14}, r = -1000;
	for (int i = 0; i < 36; i++) {
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < 4*6; i++) {
		if(i % 6 <= 3) {
			int s = 0;
			for (int j = 0; j < 7; j++) {
				s += n[i + hourglass[j]];
			}
			if(r < s) r = s;
		}
	}
	printf("%d\n", r);
	return 0;
}
