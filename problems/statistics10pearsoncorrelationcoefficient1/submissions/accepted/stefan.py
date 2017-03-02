#!/usr/bin/env python3

#Author: Stefan Toman

import math

def mean(values):
    return sum(values)/len(values)

def stddeviation(values):
    meanv = mean(values)
    variance = sum([(x-meanv)**2 for x in values])/len(values)
    return math.sqrt(variance)

def correlation(valuesx, valuesy):
    meanx, meany = mean(valuesx), mean(valuesy)
    return sum([(valuesx[i]-meanx)*(valuesy[i]-meany) for i in range(len(valuesx))])/len(valuesx)

if __name__ == '__main__':
    n = int(input())
    valuesx = list(map(float, input().split()))
    valuesy = list(map(float, input().split()))
    print(round(correlation(valuesx, valuesy)/stddeviation(valuesx)/stddeviation(valuesy), 3))
