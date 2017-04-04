#!/usr/bin/env python2
#Author: Stefan Toman

if __name__ == '__main__':
    t = int(raw_input())
    for _ in range(t):
        n = int(raw_input())
        lo, hi = 1, n
        while hi - lo > 1:
            mid = (lo + hi) / 2
            if mid * (mid + 1) / 2 > n:
                hi = mid
            else:
                lo = mid
        if lo * (lo + 1) / 2 == n:
            print "Go On Bob %d" % lo
        elif (lo + 1) * (lo + 2) / 2 == n:
            print "Go On Bob %d" % lo + 1
        else:
            print "Better Luck Next Time"
