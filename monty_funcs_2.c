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

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
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
 * @stack - pointer to start of stack
 * @line_number: count of lines executed
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int total, count = 0;

	temp = *stack;

	while  (temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	if (count < 2)
	{
		sub_error(line_number);
	}

	temp = *stack;
	total = (temp->next->n) - temp->n;
	temp->next->n = total;

	_pop(stack, line_number);
}
