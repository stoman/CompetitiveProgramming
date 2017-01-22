#!/usr/bin/env python3

#Author: Stefan Toman

def median(values):
    #we assume the data is already sorted, otherwise do values.sort()
    if len(values) % 2 == 1:
        return values[len(values)//2]
    else:
        return (values[len(values)//2-1]+values[len(values)//2])/2


if __name__ == '__main__':
    n = int(input())
    values = list(map(int, input().split()))

    values.sort()
    q1 = median(values[:n//2])
    q2 = median(values)
    q3 = median(values[(n+1)//2:])

    print(int(q1))
    print(int(q2))
    print(int(q3))
