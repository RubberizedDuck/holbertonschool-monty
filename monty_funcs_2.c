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
