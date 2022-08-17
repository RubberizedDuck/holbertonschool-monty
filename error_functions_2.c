#include "monty.h"

/**
 * error_empty_stack_pop - prints to STDERR if stack can't remove first node
 * @line_number: count of lines executed
 * Return: void
 */
int error_empty_stack_pop(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * swap_error - prints tgo STDERR if can't swaps nodes in stack
 * @line_number: count of lines executed
 * Return: void
 */

int swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
