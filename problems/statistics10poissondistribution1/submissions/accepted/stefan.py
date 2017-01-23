#!/usr/bin/env python3

#Author: Stefan Toman

import math

if __name__ == '__main__':
    l = float(input())
    k = int(input())
    print(round(l**k/math.factorial(k)*math.exp(-l), 3))
