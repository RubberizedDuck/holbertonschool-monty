#include "monty.h"

/**
 * free_dlist - free a double linked list
 * @head: pointer to start of list
 *Return: void
 */

void free_dlist(stack_t **head)
{
	stack_t *curr, *temp;

	curr = *head;

	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	*head = NULL;
}
