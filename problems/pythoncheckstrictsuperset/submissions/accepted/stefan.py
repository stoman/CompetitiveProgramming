#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    a = set(map(int, input().split()))
    n = int(input())
    r = True
    for i in range(n):
        b = set(map(int, input().split()))
        if(len(b-a) > 0 or a == b):
            r = False
    print(r)
