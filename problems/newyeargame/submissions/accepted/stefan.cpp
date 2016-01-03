//Author: Stefan Toman

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int win[2][3][2][2000][2000];

bool get(bool balsa, int s, int in0, int in1, int in2) {
	if(balsa) {
		if(in0 == 0 && in1 == 0 && in2 == 0) {
			return s != 0;
		}
		if(win[0][s][in0][in1][in2] == -1) {
			if((in0 > 0 && !get(false, s, in0-1, in1, in2)) || (in1 > 0 && !get(false, (s+2)%3, in0, in1-1, in2)) || (in2 > 0 && !get(false, (s+1)%3, in0, in1, in2-1))) {
				win[0][s][in0][in1][in2] = 1;
			}
			else {
				win[0][s][in0][in1][in2] = 0;
			}
		}
		return win[0][s][in0][in1][in2] == 1;
	}
	else {
		if(in0 == 0 && in1 == 0 && in2 == 0) {
			return s == 0;
		}
		if(win[1][s][in0][in1][in2] == -1) {
			if((in0 > 0 && !get(true, s, in0-1, in1, in2)) || (in1 > 0 && !get(true, (s+1)%3, in0, in1-1, in2)) || (in2 > 0 && !get(true, (s+2)%3, in0, in1, in2-1))) {
				win[1][s][in0][in1][in2] = 1;
			}
			else {
				win[1][s][in0][in1][in2] = 0;
			}
		}
		return win[1][s][in0][in1][in2] == 1;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	memset(win, -1, 2*3*2*2000*2000*sizeof(int));
	for (int i = 0; i < t; ++i) {
        int n;
		scanf("%d", &n);
        int in[3];
        in[0] = 0; in[1] = 0; in[2] = 0;
        for (int j = 0; j < n; j++) {
        	int a;
        	scanf("%d", &a);
        	in[a%3]++;
        }
		printf("%s\n", get(true, 0, in[0]%2, in[1], in[2]) ? "Balsa" : "Koca");
	}
	return 0;
}
