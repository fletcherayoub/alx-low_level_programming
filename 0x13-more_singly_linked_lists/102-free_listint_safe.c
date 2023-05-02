#include <stdlib.h>
#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * find_listing_loop - free a listint_t list
 * @head: the head
 *
 * Return: the staring node
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
			*h = no;
			t++;
		}
		else
		{
			*h = NULL;
			t++;
			break;
		}
	}

	*h = NULL;

	return (t);
}
