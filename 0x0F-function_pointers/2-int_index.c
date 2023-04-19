#include "function_pointers.h"

/**
 * int_index - function that search for integer
 * @array: pointer
 * @size: size of array
 * @cmp: the function
 *
 * Return: no return
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int n;

	if (size < 0)
		return (-1);
	if (array && cmp)
	{
		for (n = 0; n < size; n++)
		{
			if (cmp(array[n]))
				return (n);
		}
	}
	return (-1);
}
