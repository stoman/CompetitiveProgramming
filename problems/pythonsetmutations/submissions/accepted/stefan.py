#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    s = set(map(int, input().split()))
    m = int(input())
    for i in range(m):
        command, size = input().split()
        b = set(map(int, input().split()))
        if(command == "update"):
            s |= b
        elif(command == "intersection_update"):
            s &= b
        elif(command == "difference_update"):
            s -= b
        elif(command == "symmetric_difference_update"):
            s ^= b
    print(sum(s))
