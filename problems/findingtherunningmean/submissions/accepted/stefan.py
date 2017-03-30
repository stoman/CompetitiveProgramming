#!/usr/bin/env python2

#Author: Stefan Toman
import heapq

if __name__ == '__main__':
    n = int(raw_input())
    #heaps containing all numbers split evenly
    #elements of a are negated
    a, b = [], []
    na, nb = 0, 0
    for _ in range(n):
        m = float(raw_input())
        #insert to heap
        if na == 0 or -a[0] >= m:
            heapq.heappush(a, -m)
            na += 1
        else:
            heapq.heappush(b, m)
            nb += 1
        #balance heaps
        while na > nb + 1:
            heapq.heappush(b, -heapq.heappop(a))
            na -= 1
            nb += 1
        while na < nb:
            heapq.heappush(a, -heapq.heappop(b))
            na += 1
            nb -= 1
        #print current median
        if na == nb:
            print round((-a[0] + b[0]) / 2, 1)
        else:
            print round(-a[0], 1)
