#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - prints the multiplication of two integers
 * @argc: argument count
 * @argv: array with argument
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int n, m;

	if (argc == 1 || argc == 2)
	{
		printf("error\n");
		return (1);
	}
	else
	{
		m = 1;

		for (n = 1; n < 3; n++)
			m *= atoi(argv[n]);

		printf("%d\n", m);
	}
	return (0);
}
