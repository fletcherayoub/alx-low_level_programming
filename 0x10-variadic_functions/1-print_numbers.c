#include "variadic_functions.h"

/**
 * print_nambers - prints numbers followed by a new line
 * @separator: printe between numbers
 * @n: number of parameter
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int u;
	va_list args;

	va_start(args, n);

	for (u = 0; u < n ; u++)
	{
		printf("%d", va_arg(args, int));

		if (u < n - 1 && separator != NULL)
			printf("%s", separator);
	}
	va_end(args);
	printf("\n");
}
