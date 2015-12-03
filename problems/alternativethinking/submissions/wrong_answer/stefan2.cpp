//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int n, swap=2, r = 1;
	bool next = true;
	scanf("%d", &n);
	char c;
	scanf("%c", &c);
	if(c == '1') next = false;
	for (int i = 1; i < n; ++i) {
		scanf("%c", &c);
		bool tc = c == '1';
		if(tc == next) {
			r++;
			next = !next;
		}
		else if(swap > 0) {
			swap--;
			r++;
		}
	}
	printf("%d\n", r);
	return 0;
}
