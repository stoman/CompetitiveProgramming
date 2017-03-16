#!/usr/bin/env python2

#Author: Stefan Toman

from operator import mul

def binom(n, k):
    if n <= 0 or n < k or k < 0: return 0
    k = min(k, n-k)
    if k == 0: return 1
    return reduce(mul, range(n-k+1, n+1)) / reduce(mul, range(1, k+1))

if __name__ == '__main__':
    n = int(raw_input())
    m = len(filter(lambda x: x == 'a', raw_input().split()))
    k = int(raw_input())
    print 1. - 1. * binom(n - m, k) / binom(n, k)
