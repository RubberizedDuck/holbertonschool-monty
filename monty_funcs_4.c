#include "monty.h"

/**
 * rotr - rotates stack to the bottom
 * the last element becomes the top of the stack
 * @stack: pointer to the stack
 * @line_number: count lines executed
 * Return: void;
 */

void rotr(stack_t **stack,__attribute__ ((unused)) unsigned int line_number)
{
	int count;
	stack_t *held, *temp;

	if (stack == NULL || *stack == NULL)
		return;

	count = list_len(stack);
	if (count < 2)
		return;

	while (temp->next != NULL)
	{
		held = temp;
		temp = temp->next;
	}

	held->next = NULL;
	temp->next = *stack;
	*stack = temp;
}
