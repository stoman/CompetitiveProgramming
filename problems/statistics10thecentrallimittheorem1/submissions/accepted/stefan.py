#!/usr/bin/env python3

#Author: Stefan Toman

import math

def ncdf(mu, sigma, x):
    return (1+math.erf((x - mu)/sigma/math.sqrt(2)))/2

if __name__ == '__main__':
    limit = float(input())
    n = int(input())
    mu = float(input())
    sigma = float(input())
    print(round(ncdf(n*mu, sigma*math.sqrt(n), limit), 4))
