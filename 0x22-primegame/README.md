# 0x22-primegame
This interview algorithm project deals with a game. In the game, players are given a set of consecutive integers starting from 1 up to and including n. Players then take turns choosing a prime number from the set, which removes that number and all multiples of the number from the list. The player that has no more prime numbers left to choose loses.

[Prime Game](/0x22-primegame/0-prime_game.py)
* Write a function in Python `def isWinner(x, nums)` that plays a certain number of games where players play optimally and determines which player wins the most rounds: Maria or Ben:
  * `x` is the number of rounds
  * `nums` is a list of all `n`s, representing the max set for each round
  * Maria always goes first
  * returns the name of the player that won the most rounds
  * if the winner cannot be determined, return None
  * `n` and `x` can be assumed to not be larger than 10000

### test_files
The [test_files](/0x22-primegame/test_files/) directory contains files used to test the output of the algorithm locally.
