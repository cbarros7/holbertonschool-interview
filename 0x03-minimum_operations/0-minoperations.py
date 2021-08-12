#!/usr/bin/python3
"""
calculates the fewest number of operations needed to result
in exactly n H characters
"""


def minOperations(n):
    """ finds min. operations to reach and string """
    if type(n) != int or n <= 1:
        return 0
    res = 0
    i = 2
    while(i <= n + 1):
        if (n % i == 0):
            res += i
            n /= i
        else:
            i += 1
    return res
