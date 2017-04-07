#!/usr/bin/env python2
#Author: Stefan Toman
import sys

def dfs(c, neighbours, data, visited, sumdata):
    sumsubtree = data[c]
    mret = sys.maxint
    visited[c] = True
    for n in neighbours[c]:
        if not visited[n]:
            tsub, tret = dfs(n, neighbours, data, visited, sumdata)
            sumsubtree += tsub
            mret = min(mret, tret)
    return sumsubtree, min(abs(sumdata - 2*sumsubtree), mret)

if __name__ == '__main__':
    n = int(raw_input())
    data = map(int, raw_input().split())
    neighbours = [[] for _ in xrange(n)]
    for _ in xrange(n-1):
        a, b = map(int, raw_input().split())
        neighbours[a-1].append(b-1)
        neighbours[b-1].append(a-1)
    start = 0
    for i in xrange(n):
        if len(neighbours[i]) == 1:
            start = i
    print(dfs(start, neighbours, data, [i == start for i in xrange(n)], sum(data))[1])
