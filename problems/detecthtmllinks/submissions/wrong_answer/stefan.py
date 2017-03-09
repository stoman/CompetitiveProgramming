#!/usr/bin/env python2

import re

#Author: Stefan Toman

if __name__ == '__main__':
    #read input
    n = int(raw_input())
    s = ""
    for _ in range(n):
        s += raw_input()

    #print output
    for r in re.finditer("<a([^<>]*)href=['\"](\S*)['\"]([^<>]*)>(.*?)</a>", s):
        print "%s,%s" % (r.groups()[1], r.groups()[3])
