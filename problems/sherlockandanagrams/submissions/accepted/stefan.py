#!/usr/bin/env python2
#Author: Stefan Toman

from collections import defaultdict

if __name__ == '__main__':
    t = int(raw_input())
    for _ in range(t):
        s = raw_input()
        t = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                k = i+1
                if k + j - i < len(s):
                    d = defaultdict(int)
                    for l in range(0, j-i+1):
                        d[s[i+l]] += 1
                        d[s[k+l]] -= 1
                    while k + j - i < len(s):
                        ok = True
                        for x in d:
                            ok &= d[x] == 0
                        if ok:
                            t += 1
                        d[s[k]] += 1
                        k += 1
                        if k + j - i < len(s):
                            d[s[k + j - i]] -= 1
        print t
