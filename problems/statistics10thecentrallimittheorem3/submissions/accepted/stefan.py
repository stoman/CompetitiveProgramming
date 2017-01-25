#!/usr/bin/env python3

#Author: Stefan Toman

import math

if __name__ == '__main__':
    n = int(input())
    mu = float(input())
    sigma = float(input())
    w = float(input())
    z = float(input())
    a = -z*sigma/math.sqrt(n)+mu
    print(round(a, 2))
    print(round(2*mu-a, 2))
