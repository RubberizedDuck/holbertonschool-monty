#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to top of stack
 * @line_number: line number
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int total, count = 0;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	total = ((*stack)->n) + ((*stack)->next->n);
	/* store total in second top element */
	(*stack)->next->n = total;
	/* remove top element */
	_pop(stack, line_number);
}
