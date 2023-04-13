#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _calloc - allocate memory using malloc and initialize it
 * @nmemb: number number of elements
 * @size: the size of each element
 *
 * Return: poiter to allocate memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int n;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	for (n = 0; n < (nmemb * size); n++)
	{
		p[n] = 0;
	}
	return (p);
}
