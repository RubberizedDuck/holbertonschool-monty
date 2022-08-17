#include "monty.h"

/**
 *_isdigit - function that checks for a digit (0 through 9)
 *@c: returns 1 if c is digit
 *Return: always 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void _push(stack_t **stack,unsigned int line_number)
{
	stack_t *new;
	size_t idx = 0;
	int n;
	char *arr;

	arr = glob_var.argument;
	if (arr == NULL)
		line_num_error(line_number);
	while (arr[idx] != '\0')
	{
		if (_isdigit(arr[idx]) == 0 && arr[idx] != '-')
		{
			free_dlist(stack);
			line_num_error(line_number);
		}
		idx++;
	}
	n = atoi(arr);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_error();

	/* assign data to new node */
	new->n = n;
	new->next = *stack;
	new->prev = NULL;

	/* check to see if head if not NULL to assign correctly */
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
