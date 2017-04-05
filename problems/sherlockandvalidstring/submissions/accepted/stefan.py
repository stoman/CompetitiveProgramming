#!/usr/bin/env python2
#Author: Stefan Toman
from collections import defaultdict

def valid(s):
    cnt = defaultdict(int)
    for c in s:
        cnt[c] += 1
    minnonone = -1
    for k, v in cnt.items():
        if v > 1 and (minnonone == -1 or minnonone > v):
            minnonone = v
    possible = [0, 1]
    if not minnonone == -1:
        possible.append(minnonone)
    for i in possible:
        removed = 0
        for k, v in cnt.items():
            if v == i + 1 or (v == 1 and not i == 1):
                removed += 1
            elif not i == v:
                removed += 2
        if removed <= 1:
            return True 
    return False

if __name__ == '__main__':
    print "YES" if valid(raw_input()) else "NO"
