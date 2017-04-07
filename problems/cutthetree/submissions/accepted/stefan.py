#!/usr/bin/env python2
#Author: Stefan Toman
import sys
from Queue import Queue

if __name__ == '__main__':
    #read input
    n = int(raw_input())
    data = map(int, raw_input().split())
    neighbours = [[] for _ in xrange(n)]
    for _ in xrange(n-1):
        a, b = map(int, raw_input().split())
        neighbours[a-1].append(b-1)
        neighbours[b-1].append(a-1)
    #find start node
    q = Queue()
    for i in xrange(n):
        if len(neighbours[i]) == 1:
            q.put(i)
    #run search
    sumdata = [-1 for i in xrange(n)]
    while not q.empty():
        c = q.get()
        sumdata[c] = data[c]
        countn = 0
        for t in neighbours[c]:
            if not sumdata[t] == -1:
                sumdata[c] += sumdata[t]
            else:
                countn += 1
        if countn > 1:
            sumdata[c] = -1
        else:
            for t in neighbours[c]:
                if sumdata[t] == -1:
                    q.put(t)
    #print result
    total = sum(data)
    print min([abs(total - 2*t) for t in sumdata])
