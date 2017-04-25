#!/usr/bin/env python2

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
    if stddeviation(valuesx) == 0:
        return 0
    if stddeviation(valuesy) == 0:
        return 0
    return correlation(valuesx, valuesy)/stddeviation(valuesx)/stddeviation(valuesy)

if __name__ == '__main__':
    t = int(raw_input())
    for _ in range(t):
        n = raw_input()
        k = map(float, raw_input().split())
        s = [pearsoncorrelation(k, map(float, raw_input().split())) for _ in range(5)]
        r = 0
        for i in range(len(s)):
            if s[i] > s[r]:
                r = i
        print r+1
