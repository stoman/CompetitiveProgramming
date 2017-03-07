#!/usr/bin/env python2

#Author: Stefan Toman

if __name__ == '__main__':
    #read input
    s = raw_input()
    counts = {}
    for c in s:
        if not c in counts:
            counts[c] = 0
        counts[c] += 1

    #sort
    r = sorted(counts.items(), key=lambda x: -x[1])

    #print output
    for x in r[:3]:
        print "%s %d" % x
