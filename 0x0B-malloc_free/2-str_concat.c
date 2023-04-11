#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - function that concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer point to a new allocated memory or null
 */
char *str_concat(char *s1, char *s2)
{
	char *strnew = NULL;
	unsigned int n;
	int r1;
	int r2;
	int count;

	count = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (r1 = 0; s1[r1] != '\0'; r1++)
		;
	for (r2 = 0; s2[r2] != '\0'; r2++)
		;
	strnew = (char *)malloc((r1 + r2 + 1) * sizeof(char));
	if (strnew == NULL)
	{
		return (NULL);
	}
	for (n = 0; s1[n] != '\0'; n++)
		strnew[n] = s1[n];
	for (; s2[count] != '\0'; n++)
	{
		strnew[n] = s2[count];
		count++;
	}
	return (strnew);
}
