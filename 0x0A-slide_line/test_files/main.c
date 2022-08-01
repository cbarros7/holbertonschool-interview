#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"
/**
 * print_array - Prints out an array of integer, followed by a new line
 *
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
	size_t i;
	printf("I: ");
	for (i = 0; i < size; i++)
		printf("%s%d", i > 0 ? ", " : "", array[i]);
	printf("\n\n");
}
/**
 * print_my_array - Prints out an array of integers prepended with "M"
 *
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_my_array(int const *array, size_t size)
{
	size_t i;
	printf("M: ");
	for (i = 0; i < size; i++)
		printf("%s%d", i > 0 ? ", " : "", array[i]);
	printf("\n");
}
/**
 * print_expected_array - Prints out an array of integer, followed by a new line
 *
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_expected_array(int const *array, size_t size)
{
	size_t i;
	printf("E: ");
	for (i = 0; i < size; i++)
		printf("%s%d", i > 0 ? ", " : "", array[i]);
	printf("\n\n");
}
/**
 * compare_arrays - compares 2 arrays to see if they're equal
 *
 * @array_one: Pointer to the array of integer to be printed
 * @array_two: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static int compare_arrays(int const *array_one, int const *array_two, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
		if (array_one[i] != array_two[i])
			return (0);
	return (1);
}
/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main()
{
	/* SLIDE LEFT TESTS */
	printf("SLIDE LEFT TESTS\n");
	printf("======================================\n\n");
	/* test 1 */
	int test1[4] = {2, 2, 0, 0};
	int test1_expected[4] = {4, 0, 0, 0};
	print_array(test1, 4);
	slide_line(test1, 4, SLIDE_LEFT);
	if (compare_arrays(test1, test1_expected, 4))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test1, 4);
		print_expected_array(test1_expected, 4);
	}
	printf("======================================\n\n");
	/* test 2 */
	int test2[14] = {2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4};
	int test2_expected[14] = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	print_array(test2, 14);
	slide_line(test2, 14, SLIDE_LEFT);
	if (compare_arrays(test2, test2_expected, 14))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test2, 14);
		print_expected_array(test2_expected, 14);
	}
	printf("======================================\n\n");
	/* test 5 */
	int test5[4] = {2, 4, 8, 16};
	int test5_expected[4] = {2, 4, 8, 16};
	print_array(test5, 4);
	slide_line(test5, 4, SLIDE_LEFT);
	if (compare_arrays(test5, test5_expected, 4))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test5, 4);
		print_expected_array(test5_expected, 4);
	}
	printf("======================================\n\n");
	/* test 10 */
	int test10[5] = {2, 2, 2, 2, 2};
	int test10_expected[5] = {4, 4, 2, 0, 0};
	print_array(test10, 5);
	slide_line(test10, 5, SLIDE_LEFT);
	if (compare_arrays(test10, test10_expected, 5))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test10, 5);
		print_expected_array(test10_expected, 5);
	}
	printf("======================================\n\n");
	/* test 11 */
	int test11[5] = {0, 0, 2, 2, 4};
	int test11_expected[5] = {4, 4, 0, 0, 0};
	print_array(test11, 5);
	slide_line(test11, 5, SLIDE_LEFT);
	if (compare_arrays(test11, test11_expected, 5))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test11, 5);
		print_expected_array(test11_expected, 5);
	}
	printf("======================================\n\n");
	/* test 14 */
	int test14[6] = {16, 8, 4, 4, 4, 0};
	int test14_expected[6] = {16, 8, 8, 4, 0, 0};
	print_array(test14, 6);
	slide_line(test14, 6, SLIDE_LEFT);
	if (compare_arrays(test14, test14_expected, 6))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test14, 6);
		print_expected_array(test14_expected, 6);
	}
	printf("======================================\n\n");
	/* test 15 */
	int test15[4] = {2, 2, 2, 2};
	int test15_expected[4] = {4, 4, 0, 0};
	print_array(test15, 4);
	slide_line(test15, 4, SLIDE_LEFT);
	if (compare_arrays(test15, test15_expected, 4))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test15, 4);
		print_expected_array(test15_expected, 4);
	}
	printf("======================================\n\n");
	printf("\n\n\n");
	/* SLIDE RIGHT TESTS */
	printf("SLIDE RIGHT TESTS\n");
	printf("======================================\n\n");
	/* test 3 */
	int test3[4] = {2, 2, 2, 2};
	int test3_expected[4] = {0, 0, 4, 4};
	print_array(test3, 4);
	slide_line(test3, 4, SLIDE_RIGHT);
	if (compare_arrays(test3, test3_expected, 4))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test3, 4);
		print_expected_array(test3_expected, 4);
	}
	printf("======================================\n\n");
	/* test 4 */
	int test4[5] = {2, 2, 2, 2, 2};
	int test4_expected[5] = {0, 0, 2, 4, 4};
	print_array(test4, 5);
	slide_line(test4, 5, SLIDE_RIGHT);
	if (compare_arrays(test4, test4_expected, 5))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test4, 5);
		print_expected_array(test4_expected, 5);
	}
	printf("======================================\n\n");
	/* test 6 */
	int test6[4] = {2, 4, 8, 16};
	int test6_expected[4] = {2, 4, 8, 16};
	print_array(test6, 4);
	slide_line(test6, 4, SLIDE_RIGHT);
	if (compare_arrays(test6, test6_expected, 4))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test6, 4);
		print_expected_array(test6_expected, 4);
	}
	printf("======================================\n\n");
	/* test 7 */
	int test7[4] = {4, 4, 8, 16};
	int test7_expected[4] = {0, 8, 8, 16};
	print_array(test7, 4);
	slide_line(test7, 4, SLIDE_RIGHT);
	if (compare_arrays(test7, test7_expected, 4))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test7, 4);
		print_expected_array(test7_expected, 4);
	}
	printf("======================================\n\n");
	/* test 8 */
	int test8[5] = {0, 4, 4, 8, 16};
	int test8_expected[5] = {0, 0, 8, 8, 16};
	print_array(test8, 5);
	slide_line(test8, 5, SLIDE_RIGHT);
	if (compare_arrays(test8, test8_expected, 5))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test8, 5);
		print_expected_array(test8_expected, 5);
	}
	printf("======================================\n\n");
	/* test 9 */
	int test9[5] = {4, 4, 4, 8, 16};
	int test9_expected[5] = {0, 4, 8, 8, 16};
	print_array(test9, 5);
	slide_line(test9, 5, SLIDE_RIGHT);
	if (compare_arrays(test9, test9_expected, 5))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test9, 5);
		print_expected_array(test9_expected, 5);
	}
	printf("======================================\n\n");
	/* test 12 */
	int test12[5] = {4, 2, 2, 0, 0};
	int test12_expected[5] = {0, 0, 0, 4, 4};
	print_array(test12, 5);
	slide_line(test12, 5, SLIDE_RIGHT);
	if (compare_arrays(test12, test12_expected, 5))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test12, 5);
		print_expected_array(test12_expected, 5);
	}
	printf("======================================\n\n");
	/* test 13 */
	int test13[6] = {0, 4, 4, 4, 8, 16};
	int test13_expected[6] = {0, 0, 4, 8, 8, 16};
	print_array(test13, 6);
	slide_line(test13, 6, SLIDE_RIGHT);
	if (compare_arrays(test13, test13_expected, 6))
		printf("OK\n\n");
	else
	{
		printf("FAIL\n\n");
		print_my_array(test13, 6);
		print_expected_array(test13_expected, 6);
	}
	printf("======================================\n\n");
	return (EXIT_SUCCESS);
}
