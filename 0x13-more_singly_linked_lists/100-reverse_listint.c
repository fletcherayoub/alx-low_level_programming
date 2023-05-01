#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * reverse_listint - reverses a linked list
 * @head: head of a list
 *
 * Return: pointer to the first node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *ln, *lm;

	ln = NULL;
	lm = NULL;

	while (*head != NULL)
	{
		lm = (*head)->next;
		(*head)->next = ln;
		ln = *head;
		*head = lm;
	}

	*head = ln;
	return (*head);
}
