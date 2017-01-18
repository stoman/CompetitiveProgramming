#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    values = list(map(int, input().split()))

    #mean
    print(round(sum(values)/len(values), 1))

    #median
    values.sort()
    if n % 2 == 1:
        print(values[len(values)//2])
    else:
        print(round((values[len(values)//2-1]+values[len(values)//2])/2, 1))

    #mode
    counts = {}
    max = 0
    for x in values:
        if not x in counts:
            counts[x] = 0
        counts[x] += 1
        if(counts[x] > max):
            max = counts[x]
    for x in values:
        if counts[x] == max:
            print(x)
            break
