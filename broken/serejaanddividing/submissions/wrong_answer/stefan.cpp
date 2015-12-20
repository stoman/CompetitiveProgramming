//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		char as[1000000], bs[10000];
		int l;
		scanf("%s\n%s\n%d", as, bs, &l);
		short a[max(l, (int) strlen(as))], b[max(l, (int) strlen(bs))], c[l], inv[] = {0, 1, 4, 5, 2, 3, 6};
		memset(a, 0, max(l, (int) strlen(as))*sizeof(short));
		memset(b, 0, max(l, (int) strlen(bs))*sizeof(short));
		memset(c, 0, l*sizeof(short));
		int offset = 0;
		for (int i = 0; i < strlen(bs); ++i) {
			b[i - offset] = ((short) bs[strlen(bs) - i - 1]) - 48;
			if(offset == i && b[0] == 0) {
				offset++;
			}
		}
		for (int i = offset; i < strlen(as); ++i) {
			a[i - offset] = ((short) as[strlen(as) - i - 1]) - 48;
		}
		for (int i = 0; i < l; ++i) {
			c[i] = (a[i] * inv[b[0]]) % 7;
			short carry = 0;
			for (int j = i; j < l; ++j) {
				a[j] -= b[j-i]*c[i] + carry;
				carry = 0;
				while(a[j] < 0) {
					a[j]+=7;
					carry++;
				}
			}
		}
		bool zero = true;
		for (int i = l-1; i >= 0; --i) {
			if(!zero || c[i] != 0) {
				printf("%d", c[i]);
				zero = false;
			}
		}
		if(zero) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
