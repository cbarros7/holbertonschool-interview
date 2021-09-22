#!/usr/bin/python3
"""UTF8 Validation"""
from itertools import takewhile

NUMBER_OF_BITS_PER_BLOCK = 8
MAX_NUMBER_OF_ONES = 4


def to_bits(bytes):
    """convert to bits
    """
    for byte in bytes:
        num = []
        exp = 1 << NUMBER_OF_BITS_PER_BLOCK
        while exp:
            exp >>= 1
            num.append(bool(byte & exp))
        yield num


def validUTF8(data):
    """determines if a given data
        set represents a valid UTF-8 encoding.

    Args:
        data : data for validate

    Return:
        True if data is a valid UTF-8 encoding,
        else return False
    """
    bits = to_bits(data)
    for byte in bits:
        # single byte char
        if byte[0] == 0:
            continue

    # multi-byte character
        amount = sum(takewhile(bool, byte))
        if amount <= 1:
            return False
        if amount >= MAX_NUMBER_OF_ONES:
            return False

        for _ in range(amount - 1):
            try:
                byte = next(bits)
            except StopIteration:
                return False
            if byte[0:2] != [1, 0]:
                return False
    return True
