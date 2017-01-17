#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    print(sorted(list(set(map(int, input().split()))), reverse=True)[1])
