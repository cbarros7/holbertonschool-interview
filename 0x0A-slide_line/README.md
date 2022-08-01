# 0x0A-slide_line
This interview algorithm project is based on a single line version of the 2048 game.  The game works by sliding integers to one side of the array, left or right.  If there are two identical numbers next to each other or only separated by zeros, they are merged into one index and the number value is doubled to show the summation of the two identical numbers.

[Slide Line](/0x0A-slide_line/0-slide_line.c)
* Write a C function `int slide_line(int *line, size_t size, int direction` that slides and merges an array of integers, based on the mechanics or the 2048 game for a single horizontal line:
  * `line` points to an array of integers containing `size` elements.
  * `direction` can either be `SLIDE_LEFT` or `SLIDE_RIGHT`, macros defined in the [header file](/0x0A-slide_line/slide_line.h)
  * Returns `1` if the array of integers can successfully be shifted and merged, 0 otherwise

### test_files
The test_files/ directory contains files used to test the output of the algorithm locally.
