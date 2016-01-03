//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
	scanf("%d", &n);
	int r = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		r = max(r+1, t);
	}
	printf("%d\n", r);
	return 0;
}
