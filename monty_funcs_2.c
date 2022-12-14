#include "monty.h"

/**
 * _swap - swaps the top two stack elements
 * @stack: A pointer to doubly linked list
 * @line_number: the line at which the opcode is located
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int count = 0;

	count = list_len(stack);

	if (count < 2)
	{
		swap_error(line_number);
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
	(*stack)->prev = NULL;
}

/**
 * _nop - does nothing
 * @stack: pointer to top of stack
 * @line_number: line number
 * Return: void
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtracts the first node from the second
 * @stack: pointer to start of stack
 * @line_number: count of lines executed
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int total, count = 0;

	count = list_len(stack);

	if (count < 2)
	{
		sub_error(line_number);
	}

	temp = *stack;
	total = (temp->next->n) - temp->n;
	temp->next->n = total;

	_pop(stack, line_number);
}

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to top of stack
 * @line_number: line number
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int total, count = 0;

	count = list_len(stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->n) + ((*stack)->next->n);
	/* store total in second top element */
	(*stack)->next->n = total;
	/* remove top element */
	_pop(stack, line_number);
}

/**
 * _div - divides the top two elements of the stack
 * @stack: pointer to start fot the stack
 * @line_number: count of lines executed
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int count, total;
	stack_t *temp;

	count = list_len(stack);

	if (count < 2)
		div_error(line_number, 1);

	temp = *stack;
	if (temp->n == 0)
		div_error(line_number, 0);

	total = temp->next->n / temp->n;
	temp->next->n = total;

	_pop(stack, line_number);
}
