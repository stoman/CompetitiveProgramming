//Author: Stefan Toman

#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
	float m;
	int t, x;
	scanf("%f %d %d", &m, &t, &x);
	printf("The final price of the meal is $%d.", (int) round(m * (1 + (t + x)/100.0)));
	return 0;
}
