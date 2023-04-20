#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - prints anything
 * @format: argument types paased to function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int n;
	int m;
	char *s;

	va_start(args, format);
	n = 0;
	while (format != NULL && format[n] != '\0')
	{
		switch (format[n])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				m = 0;
				break;
			case 'i':
				printf("%i", va_arg(args, int));
				m = 0;
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				m = 0;
				break;
			case 's':
				s = va_arg(args, char*);
				if (s == NULL)
					s = "(nil)";
				printf("%s", s);
				m = 0;
				break;
			default:
				m = 1;
				break;
		}
		if (format[n + 1] != '\0' && m == 0)
			printf(", ");
		n++;
	}
	printf("\n");
	va_end(args);
}
