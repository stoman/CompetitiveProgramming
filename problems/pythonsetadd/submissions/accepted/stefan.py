#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    s = set()
    for i in range(n):
        s.add(input())
    print(len(s))
