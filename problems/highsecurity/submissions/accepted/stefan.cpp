//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n;
		scanf("%d", &n);
		bool g[2][n+1];
		for (int j = 0; j < 2; j++) {
			g[j][0] = true;
			g[j][n+1] = true;
			char c[n];
			scanf("%s", c);
			for (int k = 0; k < n; k++) {
				g[j][k+1] = c[k] == 'X';
			}
		}
		int r = 0;
		bool current[] = {false, false}, placed[] = {false, false};
		for (int j = 0; j < n+2; j++) {
			for(int k = 0; k < 2; k++) {
				if(g[k][j] && current[k]) {
					if(!placed[k]) {
						if(g[k][j-2] && current[1-k] && !placed[1-k]) {
							placed[k] = true;
							placed[1-k] = true;
							r++;
							//printf("row %d, column %d\n", 1-k, j-1);
						}
					}
				}
			}
			for(int k = 0; k < 2; k++) {
				if(g[k][j] && current[k]) {
					current[k] = false;
					if(!placed[k]) {
						placed[k] = true;
						r++;
						//printf("row %d, column %d\n", k, j-1);
					}
				}
				if(!g[k][j] && !current[k]) {
					current[k] = true;
					placed[k] = false;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, r);
	}
	return 0;
}
