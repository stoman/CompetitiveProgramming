#!/usr/bin/env python3

#Author: Stefan Toman

def sumints(n):
    return n*(n+1)//2

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())-1
        print(3*sumints(n//3) + 5*sumints(n//5) - 15*sumints(n//15))
