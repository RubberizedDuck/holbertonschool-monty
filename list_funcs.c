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

/**
 * list_len - counts the length of a singly linekd list
 * @stack: pointer to start of stack
 * Return: length of stack
 */

int list_len(stack_t **stack)
{
	int count = 0;
	stack_t *node = *stack;

	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}
