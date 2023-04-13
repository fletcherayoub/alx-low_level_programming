#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * string_nconcat - function that concatenates two strings
 *
 * @n: maximum number of bytes
 * @s1: first string
 * @s2: second string
 *
 * Return: string joined
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int f, m;
	char *p;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (f = 0; s1[f] != '\0'; f++)
	{
	}
	for (m = 0; s2[m] != '\0'; m++)
	{
	}
	if (n > m)
		n = m;
	p = malloc(((f + n) + 1));
	if (p == NULL)
		return (NULL);
	for (f = 0; s1[f] != '\0'; f++)
	{
		p[f] = s1[f];
	}
	for (m = 0; m != n; m++)
	{
		p[f] = s2[m];
		f++;
	}
	p[f] = '\0';
	return (p);
}
