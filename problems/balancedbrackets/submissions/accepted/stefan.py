#!/usr/bin/env python2

#Author: Stefan Toman

def check(s):
    match = {"(": ")", "[": "]", "{": "}"}
    stack = []
    for b in s:
        if b in match.keys():
            stack.append(b)
        elif len(stack) > 0 and match[stack.pop()] == b:
            pass
        else:
            print "NO"
            return
    print "YES" if len(stack) == 0 else "NO"

if __name__ == '__main__':
    n = int(raw_input())
    for _ in range(n):
        check(raw_input())
