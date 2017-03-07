#!/usr/bin/env python2

#Author: Stefan Toman

if __name__ == '__main__':
    #read input
    n = int(raw_input())
    words = []
    counts = {}
    for _ in range(n):
        s = raw_input()
        if not s in counts:
            counts[s] = 1
            words.append(s)
        else:
                counts[s] += 1

    #print output
    print len(words)
    for s in words:
        print counts[s],
