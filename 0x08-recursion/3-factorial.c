#include "main.h"
/**
 * factorial - return factorial of a given number
 * @n: the number to calculate the factorial
 *
 * Return: integer value
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
