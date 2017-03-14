#!/usr/bin/env python2

#Author: Stefan Toman

def quicksort(a, begin, end):
    #check whether sorting is done
    if end - begin < 1:
        return

    #sort by pivot a[end]
    smallest_larger = begin
    for i in range(begin, end):
        if a[i] <= a[end]:
            a[i], a[smallest_larger] = a[smallest_larger], a[i]
            smallest_larger += 1
    a[end], a[smallest_larger] = a[smallest_larger], a[end]
    print " ".join(map(str, a))
    quicksort(a, begin, smallest_larger - 1)
    quicksort(a, smallest_larger + 1, end)

if __name__ == '__main__':
    #read input
    n = int(raw_input())
    a = map(int, raw_input().split())
    quicksort(a, 0, n-1)
