#include <stdio.h>

/*execute*/
void first(void) __attribute__ ((constructor));

/**
 * first - prints a sentence before main
 *
 * Return: void
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
