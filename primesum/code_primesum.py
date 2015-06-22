#!/usr/bin/env python

import math 

def is_prime(num):
    """Returns True if the number is prime
    else False."""
    if num == 0 or num == 1:
        return False
    for x in range(2, num):
        if num % x == 0:
            return False
    else:
        return True

def main():
    _sum = 2
    _pointer = 2 
    _counter = 1

    while( _counter < 1000 ):
        _pointer += 1
        if(is_prime(_pointer)):
            _sum += _pointer
            _counter += 1
        else:
            pass

    print _sum

if __name__ == '__main__':
    main()
