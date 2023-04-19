#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the opcodes of its own main function
 * @argc: number arg
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int n, m;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	m = atoi(argv[1]);
	if (m < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (n = 0; n < m; n++)
	{
		printf("%02hhx", *((char *)main + n));
		if (n < m - 1)
			printf(" ");
		else
			printf("\n");
	}
	return (0);
}
