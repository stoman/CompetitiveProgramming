#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        a = set(map(int, input().split()))
        m = int(input())
        b = set(map(int, input().split()))
        print(len(a-b) == 0)
