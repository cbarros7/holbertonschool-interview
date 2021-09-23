#!/usr/bin/python3
"""UTF8 Validation"""


def validUTF8(data):
    """determines if a given data
        set represents a valid UTF-8 encoding.

    Args:
        data : data for validate

    Return:
        True if data is a valid UTF-8 encoding,
        else return False
    """
    byte_count = 0
    first = 1 << 7
    second = 1 << 6

    for n in data:
        condition = 1 << 7
        if byte_count == 0:
            while condition & n:
                byte_count += 1
                condition = condition >> 1
            if byte_count == 0:
                continue
            if byte_count == 1 or byte_count > 4:
                return False
        else:
            if not (n & first and not (n & second)):
                return False
        byte_count -= 1
    return byte_count == 0
