#!/usr/bin/env python2

#Author: Stefan Toman

import itertools
import numpy as np
from operator import mul
from sklearn.linear_model import LinearRegression

if __name__ == '__main__':
    #read input
    f, n = map(int, raw_input().split())
    X = []
    y = []
    for _ in range(n):
        line = raw_input().split()
        X.append([float(x) for x in line[:-1]])
        y.append([float(line[-1])])
    q = int(raw_input())
    Xt = []
    for _ in range(q):
        Xt.append([float(x) for x in raw_input().split()])
    #add new features as monomials of degree <= 3
    X = np.array(X)
    Xt = np.array(Xt)
    for i in range(2, 4):
        for var in itertools.product(range(f), repeat=i):
            X = np.hstack((X, reduce(mul, [X[:, j] for j in var]).reshape(-1, 1)))
            Xt = np.hstack((Xt, reduce(mul, [Xt[:, j] for j in var]).reshape(-1, 1)))
    #use sklearn to compute output
    for yt in LinearRegression().fit(X, y).predict(Xt):
        print(yt[0])
        