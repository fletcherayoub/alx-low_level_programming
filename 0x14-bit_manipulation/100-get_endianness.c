#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: big endian 0 , little endian 1
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *ld = (char *)&n;

	return ((int)*ld);
}
