#!/usr/bin/env python2

#Author: Stefan Toman

from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures

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
    #use sklearn to compute output
    pipe = Pipeline([
        ("polynomial_features", PolynomialFeatures(degree=3)),
        ("linear_regression", LinearRegression())
    ])
    for yt in pipe.fit(X, y).predict(Xt):
        print(yt[0])
        