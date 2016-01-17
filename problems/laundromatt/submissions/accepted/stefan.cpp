//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

struct interval {
	int id;
	long long end;

	interval(int id, long long end) : id(id), end(end) {};	
};

bool operator<(const interval& a, const interval& b) {
	return a.end != b.end ? a.end > b.end : a.id > b.id;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n;
        long long l, m, d;
		scanf("%lld %d %lld %lld", &l, &n, &m, &d);
		long long w[n], r = 0;
		priority_queue<interval> q;
		for (int j = 0; j < n; j++) {
			scanf("%lld", &w[j]);
			q.push(*new interval(j, w[j]));
		}
		priority_queue<interval> q2;
		int mused = 0;
		for (int j = 0; j < l; j++) {
			interval o = q.top();
			q.pop();
			if(i < 4) printf("%d\n", o.id);
			q.push(*new interval(o.id, o.end + w[o.id]));
			if(mused < m) {
				q2.push(*new interval(mused, o.end + d));
				mused++;
				if(r < o.end + d) {
					r = o.end + d;
				}
			}
			else {
				interval o2 = q2.top();
				q2.pop();
				long long e = max(o2.end, o.end) + d;
				q2.push(*new interval(o2.id, e));
				if(r < e) {
					r = e;
				}
			}
		}
		

		printf("Case #%d: %lld\n", i+1, r);
	}
	return 0;
}
