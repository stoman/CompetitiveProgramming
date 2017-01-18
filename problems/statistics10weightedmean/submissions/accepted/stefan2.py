#!/usr/bin/env python3

#Author: Stefan Toman

import numpy as np

if __name__ == '__main__':
    n = int(input())
    x = list(map(int, input().split()))
    w = list(map(int, input().split()))
    print(round(np.average(x, weights=w), 1))
