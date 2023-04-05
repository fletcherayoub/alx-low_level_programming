#include "main.h"
/**
 * _strlen_recursion - returns lenght of a string
 * @s: pointer to string
 *
 * Return: integer value
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	s++;
	return (_strlen_recursion(s) + 1);
}
