//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <utility>

using namespace std;

long gcd(long a, long b) {
  long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n;
		scanf("%d", &n);
		map<pair<long, long>, set<pair<long, long> > > lines;
        for(int j = 0; j < n; ++j) {
            long a, b, c;
            scanf("%ld %ld %ld", &a, &b, &c);
            long g = gcd(a, b);
            pair<long, long> p(b == 0 ? 1 : a/g, a == 0 ? 1 : b/g);
            long g2 = gcd(c, g);
            pair<long, long> offset(c/g2, c == 0 ? 1 : g/g2);
            lines[p].insert(offset);
        }
        set<long>::size_type r = 0;
        for(map<pair<long, long>, set<pair<long, long> > >::iterator it = lines.begin(); it != lines.end(); ++it) {
            r = max(r, it->second.size());
        }
		printf("%zu\n", r);
	}
	return 0;
}
