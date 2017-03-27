#!/usr/bin/env python2

#Author: Stefan Toman

mod = 1000000007


def euclid(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = euclid(b % a, a)
    return (g, x - (b / a) * y, y)

def modinv(a, m):
    g, x, y = euclid(a, m)
    return x % m

def factorial(n):
    r = 1
    for i in xrange(1, n+1):
        r = (r * i) % mod
    return r

def choose(n, k):
    r = factorial(n)
    r = (r * modinv(factorial(k), mod)) % mod
    r = (r * modinv(factorial(n-k), mod)) % mod
    return r

def fastexp(a, b):
    mult = a
    r = 1
    while b > 0:
        if b % 2 == 1:
            r = (r * mult) % mod
        b /= 2
        mult = (mult * mult) % mod
    return r


def solve():
    #read input
    n = int(raw_input())
    m = int(raw_input())
    if n < m: n, m = m, n

    if n == 25 and m < 24:
        return choose(n + m - 1, m)
    elif n > 25 and n - m == 2:
        return (choose(2*24, 24) * fastexp(2, m - 24)) % mod
    else:
        return 0

if __name__ == '__main__':
    print solve()
