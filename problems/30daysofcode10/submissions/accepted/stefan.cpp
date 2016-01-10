//Author: Stefan Toman

#include <stdio.h>

using namespace std;

int main() {
    int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		long n;
		scanf("%ld", &n);
		char r[32];
		for (int j = 0; j < 32; j++) {
			r[j] = (char) ((n % 2) + 48);
			n /= 2;
		}
		bool zero = true;
		for (int j = 31; j >= 0; j--) {
			if(!zero || r[j] == '1') {
				printf("%c", r[j]);
				zero = false;				
			}
		}
		printf("\n");
	}
	return 0;
}
