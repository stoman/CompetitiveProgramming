//Author: Stefan Toman

#include <stdio.h>

using namespace std;

long gcd(long a, long b) {
	if(a < b) {
		return gcd(b, a);
	}
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
    long x, y;
	scanf("%ld %ld", &x, &y);
	printf("%ld\n", gcd(x, y));
	return 0;
}
