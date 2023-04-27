#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - function that adds a new node at the beginning of a list
 * @head: pointer to the list
 * @str: string to add in the node
 *
 * Return: pointer
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *n = NULL;
	int str_len = 0;

	while (str[str_len])
		str_len++;

	n = malloc(sizeof(list_t));
	if (!n)
		return (NULL);

	n->str = strdup(str);
	n->len = str_len;
	n->next = (*head);
	(*head) = n;

	return (*head);
}
