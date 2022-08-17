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

/**
 * _push - adds new node element to start of stack
 * @stack: pointer to start of stack
 * @line_number: count of lines of executed
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
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
	/* next stack is assigned to temp */
	temp = *stack;
	/* prints each elements while the stack is not empty */
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}

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

/**
 * _pop - deletes node at given index
 * @stack: pointer to pointer to start of list
 * @line_number: the line at which the opcode is located
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL || (*stack) == NULL)
		error_empty_stack_pop(line_number);

	if (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
