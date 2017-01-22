#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n,d = map(int, input().split())
    m = int(input())
    print(round(1-(1-n/d)**m, 3))
