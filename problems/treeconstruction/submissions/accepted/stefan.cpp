//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int d[n], r[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i]);
	}
	queue<int> q;
	q.push(0);
	for (int i = 0; i < n; i++) {
		if(d[i] > 1) {
			r[i] = q.front();
			q.pop();
			for (int j = 0; j < d[i]-1; j++) {
				q.push(i+1);
			}
			if(r[i] == 0) {
				q.push(i+1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if(d[i] == 1) {
			r[i] = q.front();
			q.pop();
			if(r[i] == 0) {
				q.push(i+1);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d", r[i]);
		if(i < n-1) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
