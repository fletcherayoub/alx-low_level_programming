#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: parameter
 *
 * Return: sum
 */
int sum_them_all(const unsigned int n, ...)
{
	int s, nm;
	unsigned int u;
	va_list args;

	s = 0;
	va_start(args, n);

	if (n == 0)
		return (0);

	for (u = 0; u < n; u++)
	{
		nm = va_arg(args, int);
		s += nm;
	}
	return (s);
}
