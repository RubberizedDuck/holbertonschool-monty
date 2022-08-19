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
	int count, idx;
	stack_t *held, *temp;

	if (stack == NULL || *stack == NULL)
		return;

	count = list_len(stack);
	if (count < 2)
		return;

	idx  = 0;
        temp= *stack;
	while (idx < count)
	{
		temp = temp->next;
		idx++;
	}

	held = temp->next;
	temp->next = NULL;
	held->next = *stack;
	*stack = held;
}
