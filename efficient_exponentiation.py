# -*- coding: utf-8 -*-
"""
@author: anishukla
"""

ref= 10**9 + 7

def fast_pow(base, power):
    result = 1
    while(power > 0):
        if power % 2 == 1:
            result = (result * base) % ref
        power = power // 2
        base = (base * base) % ref

    return result


