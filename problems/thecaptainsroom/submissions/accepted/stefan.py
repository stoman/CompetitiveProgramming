#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    single = set()
    multiple = set()
    for x in map(int, input().split()):
        if x in single:
            multiple.add(x)
        else:
            single.add(x)
    print((single-multiple).pop())
