#!/usr/bin/env python3

#Author: Stefan Toman

if __name__ == '__main__':
    n = int(input())
    s = set(map(int, input().split()))
    m = int(input())
    for i in range(m):
        command, *args = input().split()
        if(command == "pop"):
            s.pop()
        elif(command == "remove"):
            s.remove(int(args[0]))
        elif(command == "discard"):
            s.discard(int(args[0]))
    print(sum(s))
