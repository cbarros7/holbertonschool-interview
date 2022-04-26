#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void siftDown(int *array, size_t size, size_t startIdx, size_t endIdx);
void swap(int **array, int idx1, int idx2);

#endif
