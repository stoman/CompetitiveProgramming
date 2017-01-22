#!/usr/bin/env python3

#Author: Stefan Toman

import math

if __name__ == '__main__':
    n = int(input())
    values = list(map(int, input().split()))

    mean = sum(values)/len(values)
    variance = sum([(x-mean)**2 for x in values])/len(values)
    stddeviation = math.sqrt(variance)
    print(round(stddeviation, 1))
    