#include "main.h"

/**
 * flip_bits - counts the number of bits needed to be flipped
 * @n: number
 * @m: number of flip n
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int c = 0;
	unsigned long int ld = n ^ m;

	while (ld)
	{
		c += ld & 1;
		ld >>= 1;
	}
	return (c);
}
