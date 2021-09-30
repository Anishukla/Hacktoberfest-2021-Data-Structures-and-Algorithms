#!/bin/python3

import math
import os
import random
import re
import sys

def yaha(n):

    if n%2 != 0:
        return "Weird"
    
    elif n%2 == 0 and n in range(2,5): 
        return "Weird"

    elif n>20 and n%2 == 0 :
        return "Not Weird"
    
    elif n%2 == 0 and n in range(6,20):
        return "Not Weird"




if __name__ == '__main__':
    n = int(input().strip())

    print(yaha(n))

    
