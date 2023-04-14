#include "main.h"
#include <stdlib.h>

/*
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer for memory allocated by malloc
 * @old_size: size previously allocated
 * @new_size: new size to reallocate
 *
 * Return: pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *old_p;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	p = malloc(new_size);
	if (!p)
		return (NULL);
	old_p = ptr;
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			p[i] = old_p[i];
	}
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			p[i] = old_p[i];
	}
	free(ptr);
	return (p);
}
