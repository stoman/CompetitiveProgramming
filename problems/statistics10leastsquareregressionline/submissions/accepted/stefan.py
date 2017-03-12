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

def pearsoncorrelation(valuesx, valuesy):
    return correlation(valuesx, valuesy)/stddeviation(valuesx)/stddeviation(valuesy)

if __name__ == '__main__':
    n = 5
    x, y, = [0] * n, [0] * n
    for i in range(n):
        x[i], y[i] = map(int, input().split())
    b = pearsoncorrelation(x, y) * stddeviation(y) / stddeviation(x)
    a = mean(y) - b * mean(x)
    print(round(a + b * 80, 3))
