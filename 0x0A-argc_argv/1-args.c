#include <stdio.h>
#include "main.h"

/**
 * main - print the number of arguments passed into it
 * @argc: count argument
 * @argv: argument
 *
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
