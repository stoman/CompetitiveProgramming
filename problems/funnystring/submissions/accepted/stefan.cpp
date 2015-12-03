//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		char s[10000];
		scanf("%s", s);
		int n = strlen(s);
		bool funny = true;
		for (int j = 1; j < n; ++j) {
			if (abs((int) (s[j] - s[j - 1])) != abs((int) (s[n - 1 - j] - s[n - j])))
				funny = false;
		}
		printf("%sFunny\n", funny ? "" : "Not ");
	}
	return 0;
}
