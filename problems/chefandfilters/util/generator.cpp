//Author: Stefan Toman

#include <stdio.h>
#include <stdlib.h>

const int LENGTH = 10;
const long long MOD = 1000000007;

void maxfiles() {
    for (int i = 1; i <= 100000; i *= 10) {
        FILE *in, *ans;
        char infile[50], ansfile[50];
        sprintf(infile, "../data/secret/max_%d.in", i);
        sprintf(ansfile, "../data/secret/max_%d.ans", i);
        in = fopen(infile, "w");
        ans = fopen(ansfile, "w");
        //photo
        fprintf(in, "1\n");
        for (int j = 0; j < LENGTH; j++) {
            fprintf(in, "b");
        }
        fprintf(in, "\n");
        //filters
        long long r = 1;
        fprintf(in, "%d\n", i);
        for (int j = 0; j < i; j++) {
            r = (2 * r) % MOD;
            for (int i = 0; i < LENGTH; i++) {
                fprintf(in, "-");
            }
            fprintf(in, "\n");
        }
        //result
        fprintf(ans, "%lld\n", r);
        fclose(in);
        fclose(ans);
    }
}

void randomfiles() {
    for (int i = 1; i < 10; i++) {
        srand(i);
        FILE *in, *ans;
        char infile[50], ansfile[50];
        sprintf(infile, "../data/secret/rand_%d.in", i);
        in = fopen(infile, "w");
        //photo
        fprintf(in, "1\n");
        for (int j = 0; j < LENGTH; j++) {
            fprintf(in, rand() % 2 == 0 ? "w" : "b");
        }
        fprintf(in, "\n");
        //filters
        fprintf(in, "10000\n");
        for (int j = 0; j < 10000; j++) {
            for (int i = 0; i < LENGTH; i++) {
                fprintf(in, rand() % 2 == 0 ? "+" : "-");
            }
            fprintf(in, "\n");
        }
        //result
        fclose(in);
    }
}

int main() {
    maxfiles();
    randomfiles();
    return 0;
}