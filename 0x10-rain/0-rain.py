#!/usr/bin/python3
"""
0_rain.py
"""


def rain(walls):
    """
    function that estimates how much water can be retained between
    single/stacked walls represented in a list of walls
    """
    water = 0
    for i in range(len(walls) - 2):
        if walls[i] and walls[i + 2]:
            water += min(walls[i], walls[i + 2])
    return water
