//Author: Stefan Toman

#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	printf("%sWeird", n % 2 == 1 || (6 <= n && n <= 20) ? "" : "Not ");
	return 0;
}
