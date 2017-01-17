#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    print(list(reversed(sorted(list(set(map(int, input().split()))))))[1])
