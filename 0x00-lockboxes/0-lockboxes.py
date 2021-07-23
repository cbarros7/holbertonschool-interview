#!/usr/bin/python3
""" Determines if all the boxes can be opened - lockboxes """


def canUnlockAll(boxes):
    """ canUnlockAll: figures out if all boxes can be opened """
    b_len = len(boxes)
    checked = [False for i in range(b_len)]
    checked[0] = True
    stack = [0]
    while len(stack):
        bx = stack.pop(0)
        for b in boxes[bx]:
            if isinstance(b, int) and b >= 0 and b < b_len and not checked[b]:
                checked[b] = True
                stack.append(b)
    return all(checked)
