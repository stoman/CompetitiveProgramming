#!/usr/bin/env python3

#Author: Stefan Toman

from sklearn.linear_model import LinearRegression

if __name__ == '__main__':
    #read input
    m, n = map(int, input().split())
    X = []
    y = []
    for _ in range(n):
        line = input().split()
        X.append([float(x) for x in line[:-1]])
        y.append([float(line[-1])])
    q = int(input())
    Xt = []
    for _ in range(q):
        Xt.append([float(x) for x in input().split()])
    #use sklearn to compute output
    for yt in LinearRegression().fit(X, y).predict(Xt):
        print(yt[0])
        