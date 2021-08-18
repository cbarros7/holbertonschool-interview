#include "sandpiles.h"

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: 3x3 matrix
 * @grid2: 3x3 matrix
 * Return: n/a
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int buffer[3][3];

	grid_sum(grid1, grid2);
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		toppling_round(grid1, buffer);
		grid_sum(grid1, buffer);
	}
}

/**
 * grid_sum - function that adds two grids element-wise
 * this operation changes grid1
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 * Return: n/a
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * is_stable - function that checks if a grid is stable
 * i.e. all values between 0 and 3
 * @grid: 3x3 grid
 * Return: 1 if stable, 0 otherwise
 */

int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * toppling_round - function that performs a toppling round
 * this operation does not change grid1
 * @grid: 3x3 grid
 * @buffer: buffer to sum with grid
 * Return: n/a
 */

void toppling_round(int grid[3][3], int buffer[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			buffer[i][j] = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				buffer[i][j] -= 4;
				if (j + 1 < 3)
					buffer[i][j + 1] += 1;
				if (j - 1 >= 0)
					buffer[i][j - 1] += 1;
				if (i + 1 < 3)
					buffer[i + 1][j] += 1;
				if (i - 1 >= 0)
					buffer[i - 1][j] += 1;
			}
		}
}

/**
 * print_grid - function that prints a grid
 * @grid: 3x3 grid
 * Return: n/a
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
