#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 105

using namespace std;

int t, n, ans, lo, hi, maxim, how;
int w[MAXN];

int main( ) {

	scanf( "%d", &t );

	for ( int T = 0; T < t; ++T ) {

		scanf( "%d", &n );

		for ( int i = 1; i <= n; ++i ) {
			scanf( "%d", &w[i] );
		}

		sort( w+1, w+n+1 );

		ans = 0;

		lo = 1;
		hi = n;

		ans = 0;

		while ( lo <= hi ) {
			maxim = w[hi];
			how = 1;
			while ( lo < hi ) {
				if ( maxim * how >= 50 ) {
					break;
				}
				++lo;
				++how;
			}

			if ( maxim * how >= 50 ) {
				++ans;
			}

			--hi;

		}

		printf( "Case #%d: %d\n", T+1, ans );

	}

	return 0;

}
