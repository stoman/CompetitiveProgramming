#!/usr/bin/env python3

#Author: Stefan Toman, adapted from sample solution

if __name__ == '__main__':
    list = [[input(), float(input())] for i in range(int(input()))]
    sortedgrades = sorted(set([entry[1] for entry in list]))
    for name in sorted(entry[0] for entry in list if entry[1] == sortedgrades[1]):
        print(name)
