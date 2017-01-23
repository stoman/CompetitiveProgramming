#!/usr/bin/env python3

#Author: Stefan Toman

import math

def ncdf(mu, sigma, x):
    return (1+math.erf((x - mu)/sigma/math.sqrt(2)))/2

if __name__ == '__main__':
    mu,sigma = map(float, input().split())
    x1 = float(input())
    x2 = float(input())
    print(round(100*(1-ncdf(mu, sigma, x1)), 2))
    print(round(100*(1-ncdf(mu, sigma, x2)), 2))
    print(round(100*ncdf(mu, sigma, x2), 2))
