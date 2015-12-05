//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
        int n, m;
		scanf("%d %d", &n, &m);
		set<int> e[n];
		for (int j = 0; j < m; j++) {
		    int x, y;
		    scanf("%d %d", &x, &y);
		    e[x-1].insert(y-1);
		    e[y-1].insert(x-1);
		}
		int s;
		scanf("%d", &s);
		s--;
		queue<int> q;
		q.push(s);
		int dist[n];
		for (int j = 0; j < n; j++) {
		    dist[j] = j == s ? 0 : -1;
		}
		while(!q.empty()) {
		    for(set<int>::iterator it = e[q.front()].begin(); it != e[q.front()].end(); ++it) {
		        if(dist[*it] == -1) {
		            dist[*it] = dist[q.front()]+6;
		            q.push(*it);
		        }
		    }
		    q.pop();
		}
        for(int j = 0; j < n; j++) {
            if(j != s) {
		        printf("%d", dist[j]);
		        if((s != n-1 && j != n-1) || (s == n-1 && j != n-2)) {
		            printf(" ");
		        }
            }
        }
        printf("\n");
	}
	return 0;
}
