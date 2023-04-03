#include "main.h"
/**
 * _memset - fill a memory with a constant byte
 * @s: adress of memory filled
 * @b: value
 * @n: index
 * return: the memory area *s
 */

char *_memset(char *s, char b, unsigned int n)
{

	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
