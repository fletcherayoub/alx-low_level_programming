#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - print all the elements
 * @h: pointer
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t f;

	f = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		f++;
	}
	return (f);
}
