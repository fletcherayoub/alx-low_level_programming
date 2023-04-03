#include "main.h"
/**
 * _memset - fill a memory with a constant byte
 * @s: adress of memory filled
 * @b: value
 * @n: index
 * return: the memory area *s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}
