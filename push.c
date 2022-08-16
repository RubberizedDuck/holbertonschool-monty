#include "monty.h"

void _push(stack_t **stack,__attribute__ ((unused)) unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;

	/* assign data to new node */
	new->next = *stack;
	new->prev = NULL;

	/* check to see if head if not NULL to assign correctly */
	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}