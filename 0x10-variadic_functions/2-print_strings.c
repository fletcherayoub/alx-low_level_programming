#include "variadic_functions.h"

/**
 * print_strings - prints strings followed by new line
 * @separator: print string
 * @n: number of string
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int u;
	char *s;

	va_start(args, n);

	for (u = 0; u < n; u++)
	{
		s = va_arg(args, char *);
		printf("%s%s", s ? s : "(nil)", (u == n - 1 || !separator) ? "" : separator);
	}

	va_end(args);
	printf("\n");
}

