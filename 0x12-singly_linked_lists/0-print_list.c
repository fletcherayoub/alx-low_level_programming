#include "lists.h"
#include <stdio.h>

/**
 * print_list - print all the elements of a list
 * @h: pointer to a list
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t index;
	index = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		index++;
	}
	return (index);
}
