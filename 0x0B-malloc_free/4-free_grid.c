#include "main.h"
#include <stdlib.h>

/**
 * free_grid - free a 2 dimensional
 * @grid: the 2-demensional array
 * @height: hight of grid
 *
 * Return: 0
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
