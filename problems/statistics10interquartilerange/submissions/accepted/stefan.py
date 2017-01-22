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
    x = list(map(int, input().split()))
    f = list(map(int, input().split()))
    #this problem can also be done without explicitly computing this list,
    #but the input is small so we do it for the sake of simplicity
    values = [x[i] for i in range(n) for j in range(f[i])]

    values.sort()

    #this is correct according to the last problem
    q1 = median(values[:len(values)//2])
    q2 = median(values)
    q3 = median(values[(len(values)+1)//2:])

    #this is what they seem to want...
    if n % 2 == 0:
        q1 = median(values[:len(values)//2])
        q3 = median(values[len(values)//2:])
    else:
        q1 = median([x for x in values[:len(values)//2] if x != values[len(values)//2]])
        q3 = median([x for x in values[(len(values)+1)//2:] if x != values[len(values)//2]])

    #print(values)
    #print(q2)
    #print([x for x in values[:len(values)//2] if x != q2])
    #print([x for x in values[(len(values)+1)//2:] if x != q2])

    print(round(float(q3-q1), 1))
