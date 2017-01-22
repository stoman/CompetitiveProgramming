#!/usr/bin/env python3

#Author: Stefan Toman

from math import factorial

def choose(n, k):
    return factorial(n)/factorial(k)/factorial(n-k)

def binom(n, k, p):
    return choose(n, k)*(p**k)*((1-p)**(n-k))

if __name__ == '__main__':
    p,n = map(int, input().split())
    print(round(sum([binom(n, k, p/100) for k in range(3)]), 3))
    print(round(sum([binom(n, k, p/100) for k in range(2, n+1)]), 3))
