//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        long long n, m, z, l, r, b;
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &n, &m, &z, &l, &r, &b);
		long long seated = 0, a = 0;
		
		//even number of seats
		if(m % 2 == 0) {
		    m--;
		    a = min(l, n);
		    l -= a;
		    seated += a;

		    a = min(r, n-seated);
		    r -= a;
		    seated += a;

		    a = min(z, n-seated);
		    z -= a;
		    seated += a;
		}

		//rows with Ls and one B
		if(m > 1) {
    		a = min(l/(m-1), b);
    		a = min(a, n);
    		n -= a;
    		l -= a*(m-1);
    		b -= a;
    		seated += a*m;
    
    		//rows with Rs and one B
    		a = min(r/(m-1), b);
    		a = min(a, n);
    		n -= a;
    		r -= a*(m-1);
    		b -= a;
    		seated += a*m;
		}

		//rows with Ls
		a = min(l/m, n);
		n -= a;
		l -= a*m;
		seated += a*m;

		//rows with Rs
		a = min(r/m, n);
		n -= a;
		r -= a*m;
		seated += a*m;

		//rows with remaining Ls and Rs
		for (long long j = 0; 0 < n && (l > 0 || r > 0); j++) {
	        long long taken = 0;
	        //Ls from the left, leave one free
	        long long ls = min(l, m-1);
	        l -= ls;
	        taken += ls;
    		//printf("-> ls %I64d\n", ls);
	        
	        //Rs from the right, leave one free
            long long rs = min(m-taken-1, r);
            r -= rs;
            taken += rs;
    		//printf("-> rs %I64d\n", rs);
            
            //single empty seat?
            if(taken == m-1) {
                if(b > 0) {
                    b--;
                    taken++;
            		//printf("-> +b\n");
                }
                else if(l > 0) {
                    l--;
                    taken++;
            		//printf("-> +l\n");
                }
                else if(r > 0) {
                    r--;
                    taken++;
            		//printf("-> +r\n");
                }
                else if(z > 0) {
                    z--;
                    taken++;
            		//printf("-> +z\n");
                }
            }
            else {
                //fill remaining seats with B and Z
                long long k = min(min(b, z), (m-taken)/2);
                b -= k;
                z -= k;
                taken += 2*k;
        		//printf("-> k %I64d\n", k);
                
                //only B or Z remaining
                if(b > 0) {
                    //only B
                    long long bs = min(b, (m-taken+1)/2);
                    b -= bs;
                    taken += bs;
            		//printf("-> bs %I64d\n", bs);
                }
                else {
                    //only Z
                    long long zs = max((long long) 0, min(z, m-taken));
                    z -= zs;
                    taken += zs;
            		//printf("-> zs %I64d\n", zs);
                }
            }
            
            //sum up
            seated += taken;
            n--;
    		//printf("=> taken %I64d\n", taken);
		}
        
        //rows with Bs and Zs
        if(m > 1) {
            a = min(b/((m+1)/2), z/(m/2));
            a = min(a, n);
            n -= a;
            b -= a*((m+1)/2);
            z -= a*(m/2);
            seated += a*m;
        }
        
        //rows with remaining Bs or Zs
        a = min(b, n*((m+1)/2));
        b -= a;
        seated += a;
        seated += min(n*m-a, z);
        z -= min(n*m-a, z);
        
		printf("%I64d\n", seated);
	}
	return 0;
}
