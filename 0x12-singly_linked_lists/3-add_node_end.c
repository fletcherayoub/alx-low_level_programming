#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node_end - function that adds a new node at the end of a list.
 * @head: pointer to list_t
 * @str: string to add
 *
 * Return: adresss
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n, *m;
	size_t f;

	n = malloc(sizeof(list_t));
	if (n == NULL)
		return (NULL);
	n->str = strdup(str);

	for (f = 0; str[f]; f++)
		;

	n->len = f;
	n->next = NULL;
	m = *head;

	if (m == NULL)
	{
		*head = n;
	}
	else
	{
		while (m->next != NULL)
			m = m->next;
		m->next = n;
	}

	return (*head);
}
