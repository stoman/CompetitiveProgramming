#!/usr/bin/env python2

#Author: Stefan Toman

def subsequences(a, b):
    dp = [[0 for _ in range(len(b)+1)] for _ in range(2)]
    for i in range(len(a)):
        for j in range(len(b)):
            dp[(i+1)%2][j+1] = dp[i%2][j+1] + dp[(i+1)%2][j] + 1
            if a[i] != b[j]:
                dp[(i+1)%2][j+1] -= dp[i%2][j] + 1
            dp[(i+1)%2][j+1] %= 1000000007
    return dp[len(a)%2][len(b)] - dp[(len(a) - 1)%2][len(b)]

if __name__ == '__main__':
    t = int(raw_input())
    for _ in range(t):
        s = raw_input().strip()
        r = 0
        for i in range(1, len(s)):
            r += subsequences(s[:i], s[i:])
            r %= 1000000007
        print r
