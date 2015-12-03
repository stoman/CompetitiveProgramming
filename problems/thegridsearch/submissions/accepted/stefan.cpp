//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int r, c;
	    scanf("%d %d", &r, &c);
        char g[r][c];
        for(int j = 0; j < r; j++) {
            scanf("%s", g[j]);
        }
        int r2, c2;
	    scanf("%d %d", &r2, &c2);
        char p[r2][c2];
        for(int j = 0; j < r2; j++) {
            scanf("%s", p[j]);
        }
        bool found = false;
        for(int j = 0; !found && j <= r - r2; j++) {
            for(int k = 0; !found && k <= c - c2; k++) {
                bool ok = true;
                for(int m = 0; ok && m < r2; m++) {
                    for(int n = 0; ok && n < c2; n++) {
                        ok = ok && g[j + m][k + n] == p[m][n];
                    }
                }
                if(ok) {
                    found = true;
                }
            }      
        }
		printf("%s\n", found ? "YES" : "NO");
	}
}
