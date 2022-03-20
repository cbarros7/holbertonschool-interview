#!/usr/bin/python3
"""
Implementing N queens
"""
import sys


def recurse(board, row):
    """
    utility function that positions the queens on the board
    and uses recursion ("backtracking") to ensure that all the positions
    taken are valid positions (i.e. non-attacking positions)
    """

    N = len(board)

    # Exit rercusion condition
    if row == N:
        print(board)
    else:
        for col in range(N):
            board[row][1] = col
            if valid_position(board, row):
                recurse(board, row + 1)


def valid_position(board, row):
    """
    function that ensures that a given position on the board is
    a valid position (i.e. non-attacking position)
    """

    for i in range(row):
        if board[row][1] == board[i][1]:
            return False
        # Clear the diagonales
        if abs(board[row][1] - board[i][1]) == row - i:
            return False
    return True


if __name__ == '__main__':

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        N = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)

    board = [[row, 0] for row in range(N)]
    recurse(board, 0)
