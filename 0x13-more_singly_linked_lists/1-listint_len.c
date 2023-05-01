#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * listint_len - returns the number in linked list
 * @h: pointer to the head
 * Return: the number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}
