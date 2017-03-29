#!/usr/bin/env python2

#Author: Stefan Toman

class DigitCount:
    def __init__(self, string):
        self.counts = {str(i): 0 for i in xrange(10)}
        for c in string:
            self.counts[c] += 1

    def __le__(self, other):
        for i in self.counts:
            if self.counts[i] > other.counts[i]:
                return False
        return True

def solve(string):
    if len(string) == 1:
        return "YES" if int(string) % 8 == 0 else "NO"
    if len(string) == 2:
        return "YES" if int(string) % 8 == 0 or int(string[1] + string[0]) % 8 == 0 else "NO"
    else:
        ncounts = DigitCount(string)
        for i in xrange(0, 1000, 8):
            if DigitCount("%03d" % i) <= ncounts:
                return "YES"
        return "NO"


if __name__ == '__main__':
    #read input
    t = int(raw_input())
    for _ in xrange(t):
        print solve(raw_input())
