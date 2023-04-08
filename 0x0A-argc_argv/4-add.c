#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

/**
 * main - program that adds positive numbers
 * @argc: number of command
 * @argv: array
 *
 * Return: 1 if not integer , 0 otherwise
 */

int main(int argc, char *argv[])
{
	int n, m, len, sum;
	char *ptr;

	if (arg < 2)
		printf("0\n");
	else
	{
		sum = 0;
		for (n = 1; n < argc; n++
