#include "monty.h"

/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to top of stack
 * @line_number: line number
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	/* if stack is empty, print error message */
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* prints the value at the top of stack, followed by new line */
	printf("%d\n", (*stack)->n);
}
