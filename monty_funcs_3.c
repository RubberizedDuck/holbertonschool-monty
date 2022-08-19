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

/**
 * _mod - computes the remainder of the divison of the second node
 * and the first node
 * @stack: pointer to start of stack
 * @line_number: count of lines executed
 * Return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int total, count;

	count  = list_len(stack);
	if (count < 2)
		mod_error(line_number, 1);

	if ((*stack)->n == 0)
		mod_error(line_number, 0);

	total = ((*stack)->next->n) % (*stack)->n;

	(*stack)->next->n = total;
	_pop(stack, line_number);
}

/**
 * pchar - prints out the char at the top of the stack
 * @stack: pointer to start of stack
 * @line_number: count of lines executed
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack == NULL || *stack == NULL)
		pchar_error(line_number, 0);

	n = (*stack)->n;

	if (n < 0 || n > 127)
		pchar_error(line_number, 1);

	putchar(n);
}
