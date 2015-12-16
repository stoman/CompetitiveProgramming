//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n;
		scanf("%d", &n);
		int r = 1000;
		for (int j = 0; j < n; j++) {
			char s[100];
			scanf("%s", s);
			int a = 0;
			for (int k = 0; k < strlen(s); k++) {
				a += s[k] == 'a' ? 1 : 0;
			}
			r = min(r, min(a, (int) strlen(s) - a));
		}
		printf("%d\n", r);
	}
	return 0;
}
