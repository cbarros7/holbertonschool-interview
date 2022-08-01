#include "search_algos.h"

/**
 * advanced_binary - uses advanced binary search to search for first time
 * a given value appears in a sorted array using recursion
 *
 * @array: pointer to the first element of the sorted array to search in;
 * array is sorted in ascending order
 * @size: number of elements in array
 * @value: the given value to search for
 *
 * Return: the first index where value is located, or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	int half = ((size - 1) / 2), result = 0;
	size_t i = 0;

	if (array == NULL || size < 1)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != (size - 1))
			printf(", ");
		else
			printf("\n");
	}

	if (array[half] == value && half == 0)
		return (half);
	else if (size == 1)
		return (-1);

	if (array[half] >= value)
		return (advanced_binary(array, half + 1, value));

	half++;
	result = advanced_binary(&array[half], size - half, value);
	if (result == -1)
		return (-1);
	return (half + result);
}
