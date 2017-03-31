#!/usr/bin/env python2

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(raw_input())
    for _ in range(n):
        r1, r2 = map(float, raw_input().split())
        x1 = map(float, raw_input().split())
        a1 = map(float, raw_input().split())
        x2 = map(float, raw_input().split())
        a2 = map(float, raw_input().split())
        dist = (r1 + r2) ** 2
        zero = sum([(x1[i] - x2[i]) ** 2 for i in range(3)])
        one = sum([2 * (x1[i] - x2[i]) * (a1[i] - a2[i]) for i in range(3)])
        two = sum([(a1[i] - a2[i]) ** 2 for i in range(3)])
        x = -one / 2 / two
        print "YES" if zero <= dist or (x >= 0 and two * x * x + one * x + zero <= dist) else "NO"
