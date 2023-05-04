#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer contain binary number
 *
 * Return: converted value
 */
unsigned int binary_to_uint(const char *b)
{
	int n = 0;
	unsigned int dn = 0;

	if (!b)
		return (0);
	for (n = 0; b[n]; n++)
	{
		if (b[n] < '0' || b[n] > '1')
			return (0);
		dn = 2 * dn + (b[n] - '0');
	}
	return (dn);
}
