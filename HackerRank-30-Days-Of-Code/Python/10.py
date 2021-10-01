#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    n = int(input())

    b = bin(n).replace("0b","")

    l = b.split("0")
    # print(l)
    l.sort(reverse=True)
    # print(l)
    print(len(l[0]))
