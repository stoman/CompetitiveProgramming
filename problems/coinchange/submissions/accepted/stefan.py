#!/usr/bin/env python2

#Author: Stefan Toman

if __name__ == '__main__':
    n, m = map(int, raw_input().split())
    cs = list(map(int, raw_input().split()))
    dp = [0 if i > 0 else 1 for i in range(n+1)]
    for c in cs:
        for i in range(n-c+1):
            dp[i+c] += dp[i]
    print dp[n]