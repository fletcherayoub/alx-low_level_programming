#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional
 * @width: the width of the 2-dimensional array
 * @height: the height of the 2-dimensional array
 *
 * Return: pointer to array
 */
int **alloc_grid(int width, int height)
{
	int **alloc;
	int n, m;

	if (width <= 0 || height <= 0)
		return (NULL);

	alloc = (int **) malloc(sizeof(int *) * height);
	if (alloc == NULL)
		return (NULL);

	for (n = 0; n < height; n++)
	{
		alloc[n] = (int *) malloc(sizeof(int) * width);
		if (alloc[n] == NULL)
		{
			free(alloc);
			for (m = 0; m <= n; m++)
				free(alloc[m]);
			return (NULL);
		}
	}

	for (n = 0; n < height; n++)
		for (m = 0; m < width; m++)
			alloc[n][m] = 0;
	return (alloc);
}
