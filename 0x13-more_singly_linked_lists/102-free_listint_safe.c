#include <stdlib.h>
#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * free_listint_safe - free a listint_t list
 * @h: pointer for node
 *
 * Return: free list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t t = 0;
	listint_t *no;
	int ln;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		ln = *h - (*h)->next;
		if (ln > 0)
		{
			no = (*h)->next;
			free(*h);
			*h = no;
			t++;
		}
		else
		{
			free(*h);
			*h = NULL;
			t++;
			break;
		}
	}

	*h = NULL;

	return (t);
}
