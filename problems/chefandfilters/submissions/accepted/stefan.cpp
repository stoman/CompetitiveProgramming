//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int LENGTH = 10;
const long long MOD = 1000000007;

int readLine(char one) {
    char t[LENGTH];
    scanf("%s", t);
    int r = 0;
    for (int j = 0; j < LENGTH; j++) {
        r *= 2;
        if(t[j] == one) {
            r++;    
        };
    }
    return r;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
	    int s = readLine('w');
		bool r[1<<LENGTH];
		for (int j = 0; j < 1<<LENGTH; j++) {
		    r[j] = false;
		}
		r[s] = true;
		long long p = 1;
        int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
		    int f = readLine('+');
		    if(r[s^f]) {
		        //if we don't find anything new for s we will never find some new photo
		        //multiply result by 2 for the new cycle
		        p = (2 * p) % MOD;
		    }
		    else {
		        //mark new photos as reachable
    		    for (int k = 0; k < 1<<LENGTH; k++) {
    		        r[k] |= r[f^k];
    		    }
		    }
		}
		printf("%lld\n", r[0] ? p : 0);
	}
	return 0;
}
