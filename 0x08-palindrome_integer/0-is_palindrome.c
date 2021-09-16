#include "palindrome.h"

/**
 * is_palindrome - function that checks if a given integer is a palindrome
 * @n: unsigned long integer
 * Return: 1 if integer is a palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int len = 0, j = 0;
	char str[21];

	/* printf("%lu\n", n); */
	len = sprintf(str, "%lu", n);
	/* printf("%s\n", str); */
	for (j = 0; j < len; j++)
		if (str[j] != str[len - 1 - j])
			return (0);
	return (1);
}
