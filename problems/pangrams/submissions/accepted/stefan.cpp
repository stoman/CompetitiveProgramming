//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char s[1000];
	scanf("%[^\n]", s);
	bool used[26] = {};
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] != ' ') {
			used[(((int) s[i]) - 65) % 32] = true;
		}
	}
	bool ok = true;
	for(int i = 0; i < sizeof(used); i++) {
		ok &= used[i];
	}
	printf("%spangram\n", ok ? "" : "not ");
	return 0;
}
