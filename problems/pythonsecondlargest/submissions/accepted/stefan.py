#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    l = list(set(map(int, input().split())))
    l.sort()
    print(l[len(l)-2])
