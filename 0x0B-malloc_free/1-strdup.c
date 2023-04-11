#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - function that returns a pointer to new space in memory,
 * which contains a copy of the string given parameter
 *
 * @str: array
 *
 * Return: pointer
 */

char *_strdup(char *str)
{
	int n, m;
	char *string;

	if (str == NULL)
	{
		return (0);
	}
	n = 0;

	while (*(str + n) != '\0')
	{
	n++;
	}
string = malloc(n + 1);
if (string == 0)
{
	return (0);
}
for (m = 0; m < n; m++)
{
	*(string + m) = *(str + m);
}
return (string);
}
