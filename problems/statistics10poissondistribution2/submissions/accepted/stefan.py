#!/usr/bin/env python3

#Author: Stefan Toman

import math

if __name__ == '__main__':
    la, lb = map(float, input().split())
    print(round(160+40*(la+la**2), 3))
    print(round(128+40*(lb+lb**2), 3))
