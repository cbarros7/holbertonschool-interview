#include "menger.h"

/**
 * menger - function that draws the 2D Menger
 * @level: level of the Menger to draw
 * Return: void
 */

void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (hashtag(row, col))
				printf("#");
			else
				printf(" ");
			col++;
		}
		printf("\n"), row++;
	}
}

/**
 * hashtag - function that prints "#" or " "
 * @row: number of rows composing the Menger
 * @col: number of columns composing the Menger
 * Return: 1 if "#" shall be printed, 0 otherwise
 */

int hashtag(int row, int col)
{
	while (row && col)
	{
		if (row % 3 != 1 || col % 3 != 1)
			row /= 3, col /= 3;
		else
			return (0);
	}
	return (1);
}
