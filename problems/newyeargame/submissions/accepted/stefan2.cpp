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
        int in[3];
        in[0] = 0; in[1] = 0; in[2] = 0;
        for (int j = 0; j < n; j++) {
        	int a;
        	scanf("%d", &a);
        	in[a%3]++;
        }
		printf("%s\n", in[1] %2 == 0 && in[2] %2 == 0 ? "Koca" : "Balsa");
	}
	return 0;
}
