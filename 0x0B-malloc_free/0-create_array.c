#include "main.h"
#include <stdlib.h>
/**
 * create_array - create array of char
 * @size: size of the array
 * @c: char
 *
 * Return: void
 */
char *create_array(unsigned int size, char c)
{
	char *s;
	unsigned int n;

	if (!size)
		return (NULL);
	s = malloc(sizeof(char) * size);

	if (s == NULL)
		return (NULL);
	for (n = 0; n < size; n++)
		s[n] = c;
	return (s);
}
