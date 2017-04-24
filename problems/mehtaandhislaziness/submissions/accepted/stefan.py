#!/usr/bin/env python2

#Author: Stefan Toman

from fractions import Fraction
import math

if __name__ == '__main__':
    t = int(raw_input())
    for _ in range(t):
        n = int(raw_input())
        d = set([1])
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                d |= set([i, n/i])
        squares = set([i*i for i in range(2, 1010, 2)])
        print str(Fraction(len(d & squares), len(d)))
