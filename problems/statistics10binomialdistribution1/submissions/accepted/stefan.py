#!/usr/bin/env python3

#Author: Stefan Toman

from math import factorial

def choose(n, k):
    return factorial(n)/factorial(k)/factorial(n-k)

def binom(n, k, p):
    return choose(n, k)*(p**k)*((1-p)**(n-k))

if __name__ == '__main__':
    p,q = map(float, input().split())
    print(round(sum([binom(6, k, p/(p+q)) for k in range(3, 7)]), 3))
