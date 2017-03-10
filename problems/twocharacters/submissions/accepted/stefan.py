#!/usr/bin/env python2

#Author: Stefan Toman

if __name__ == '__main__':
    #read input
    n = int(raw_input())
    s = raw_input()

    #count strings
    t = 0
    chars = set(s)
    for i in chars:
        for j in chars:
            if not i == j:
                first = True
                tt = 0
                ok = True
                for c in s:
                    if (first and c == i) or (not first and c == j):
                        tt += 1
                        first = not first
                    elif c in [i, j]:
                        ok = False
                if ok:
                    t = max(t, tt)

    #print output
    print t
