#include "monty.h"

/**
 * _mul - multiplies the first node from the second
 * @stack: pointer to start of stack
 * @line_number: count of lines executed
 * Return: void
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int total, count = 0;

	count = list_len(stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	total = ((*stack)->n) * ((*stack)->next->n);
	/* store total in second top element */
	(*stack)->next->n = total;
	/* remove top element */
	_pop(stack, line_number);
}
