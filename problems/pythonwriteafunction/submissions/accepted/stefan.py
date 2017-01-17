#!/usr/bin/env python3

#Author: Stefan Toman

def is_leap(year):
    #custom code starts here
    if year % 4 != 0:
        return False
    if year % 400 == 0:
        return True
    if year % 100 == 0:
        return False
    return True
    #custom code ends here

if __name__ == '__main__':
    year = int(input())
    print(is_leap(year))
