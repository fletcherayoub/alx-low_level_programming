#include "main.h"

/**
 * set_bit - sets the value of a bit of a given index to 1
 * @n: pointer to bit
 * @index: index to set the value at indices
 *
 * Return: if error -1 otherwise 1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (8 * (sizeof(unsigned long int))))
	{
		return (-1);
	}
	*n ^= (1 << index);

	return (1);
}
