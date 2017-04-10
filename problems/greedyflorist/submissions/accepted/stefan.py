#!/usr/bin/env python2

#Author: Stefan Toman

if __name__ == '__main__':
    n, k = map(int, raw_input().split())
    f = map(int, raw_input().split())
    r = 0
    for i, p in enumerate(sorted(f, key=lambda t: -t)):
        r += ((i / k) + 1) * p
    print r
