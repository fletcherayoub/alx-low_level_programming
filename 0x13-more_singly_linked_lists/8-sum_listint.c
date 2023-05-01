#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * sum_listint - function returns the sum of all data
 * @head: pointer
 *
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int asum = 0;

	while (head != NULL)
	{
		asum += head->n;
		head = head->next;
	}

	return (asum);
}
