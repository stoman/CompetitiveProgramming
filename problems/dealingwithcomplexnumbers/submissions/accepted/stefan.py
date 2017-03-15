#!/usr/bin/env python2

#Author: Stefan Toman

import math

class Complex(object):
    def __init__(self, real, imaginary):
        self.re = real
        self.im = imaginary
        
    def __add__(self, no):
        return Complex(
            self.re + no.re,
            self.im + no.im
        )

    def __sub__(self, no):
        return Complex(
            self.re - no.re,
            self.im - no.im
        )
        
    def __mul__(self, no):
        return Complex(
            self.re*no.re - self.im*no.im,
            self.re*no.im + self.im*no.re
        )

    def __div__(self, no):
        return Complex(
            (self.re*no.re + self.im*no.im) / (no.re**2 + no.im**2),
            (self.im*no.re - self.re*no.im) / (no.re**2 + no.im**2)
        )
        
    def mod(self):
        return Complex(
            math.sqrt(self.re**2 + self.im**2),
            0
        )

    #given code starts here
    def __str__(self):
        if self.im == 0:
            result = "%.2f+0.00i" % (self.re)
        elif self.re == 0:
            if self.im >= 0:
                result = "0.00+%.2fi" % (self.im)
            else:
                result = "0.00-%.2fi" % (abs(self.im))
        elif self.im > 0:
            result = "%.2f+%.2fi" % (self.re, self.im)
        else:
            result = "%.2f-%.2fi" % (self.re, abs(self.im))
        return result


if __name__ == '__main__':
    c = map(float, raw_input().split())
    d = map(float, raw_input().split())
    x = Complex(*c)
    y = Complex(*d)
    print '\n'.join(map(str, [x+y, x-y, x*y, x/y, x.mod(), y.mod()]))
