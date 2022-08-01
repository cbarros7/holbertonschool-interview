# 0x12-advanced_binary_search
This interview algorithm project works with binary search.  Basic binary search does not necessarily return the index of the first value in the array that matches the given value (if this value appears more than once).  Advanced binary search not only finds the matching value, but returns the index of the first matching value.

[Advanced Binary Search](/0x12-advanced_binary_search/0-advanced_binary.c)
* Write a function in C `int advanced_binary(int *array, size_t size, int value)` that searches for a value in a sorted array of integers using advanced binary search:
  * must implement binary search to return the first index where the value is located
  * given array will be sorted in ascending order
  * expected to print the subarray every time the array is split to show subarray searching in
  * program must use recursion and may only use one loop to print the array

### test_files
The test_files/ directory contains files used to test the output of the algorithm locally and all initially given source code