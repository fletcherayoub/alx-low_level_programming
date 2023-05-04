#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @n: pointer
 * @index: index to set the value
 *
 * Return: error -1 otherwise -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (8 * (sizeof(unsigned long int))))
	{
		return (-1);
	}
	*n &= ~(1 << index);

	return (1);
}
