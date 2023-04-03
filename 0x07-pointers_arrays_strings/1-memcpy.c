#include "main.h"
/**
 * _memcpy - copies memory area
 * @dest: memory stored
 * @src: memory copied
 * @n: number of bytes
 *
 * return: memory with n byted changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
int m = 0;
int i = n;
for (; m < i; m++)
{
dest[m] = src[m];
n--;
}
return (dest);
}
