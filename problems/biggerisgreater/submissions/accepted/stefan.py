#!/usr/bin/env python2

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(raw_input())
    for _ in range(n):
        s = [c for c in raw_input().strip()]
        for i in range(len(s) - 1, 0, -1):
            if s[i] > s[i-1]:
                j = i
                for k in range(j+1, len(s)):
                    if s[i-1] < s[k] and s[k] < s[j]:
                        j = k
                s[i-1], s[j] = s[j], s[i-1]
                for l, c in enumerate(sorted(s[i:])):
                    s[i+l] = c
                print "".join(s)
                break
        else:
            print "no answer"
