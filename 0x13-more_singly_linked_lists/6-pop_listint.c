#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * pop_listint - deletes the head of a listint_t and return
 * the head node data
 * @head: head of a list
 *
 * Return: node
 */
int pop_listint(listint_t **head)
{
	int hn;
	listint_t *nm;
	listint_t *nt;

	if (*head == NULL)
		return (0);

	nt = *head;
	hn = nt->n;
	nm = nt->next;
	free(nt);
	*head = nm;
	return (hn);
}
