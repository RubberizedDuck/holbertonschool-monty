#include "monty.h"

/**
 * _pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: pointer to top of stack
 * @line_number: line number
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/* if stack is empty, print nothing */
	if (*stack == NULL || stack == NULL)
		return;
	/* temp node points to head node */
	temp = *stack;
	/* prints each elements while the stack is not empty */
	while(temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
