#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - create an array of integers
 * @min: min value
 * @max: max value
 *
 * Return: pointer to the allocated memory
 */
int *array_range(int min, int max)
{
	int *p;
	int n;

	if (min > max)
		return (NULL);
	p = malloc(sizeof(*p) * ((max - min) + 1));
	if (p == NULL)
		return (NULL);
	for (n = 0; min <= max; min++, n++)
		p[n] = min;
	return (p);
}
