#!/usr/bin/env python3

#Author: Stefan Toman

def score(x, a, b):
    if x in a:
        return 1
    elif x in b:
        return -1
    else:
        return 0

if __name__ == '__main__':
    n, m = map(int, input().split())
    arr = map(int, input().split())
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    print(sum([score(x, a, b) for x in arr]))
