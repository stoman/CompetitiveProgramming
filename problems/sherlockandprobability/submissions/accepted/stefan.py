#!/usr/bin/env python2

#Author: Stefan Toman

from fractions import Fraction

if __name__ == '__main__':
    t = int(raw_input())
    for _ in xrange(t):
        #read input
        n, k = map(int, raw_input().split())
        s = raw_input().strip()
        #compute sliding window
        count = sum([1 for i in s[:k+1] if i == "1"])
        num = 0
        for i in xrange(n):
            if s[i] == "1":
                num += count
            if i - k >= 0 and s[i - k] == "1":
                count -= 1
            if i + k + 1 < n and s[i + k + 1] == "1":
                count += 1
        r = Fraction(num, n * n)
        #print output
        if r == 0:
            print "0/1"
        elif r == 1:
            print "1/1"
        else:
            print r
