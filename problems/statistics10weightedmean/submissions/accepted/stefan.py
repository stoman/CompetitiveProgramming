#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    x = list(map(int, input().split()))
    w = list(map(int, input().split()))
    print(round(sum([x[i]*w[i] for i in range(n)])/sum(w), 1))
