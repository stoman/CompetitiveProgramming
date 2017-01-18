#!/usr/bin/env python3

#Author: Stefan Toman

def average(array):
    #custom code starts here
    return sum(set(array))/len(set(array))
    #custom code ends here

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)