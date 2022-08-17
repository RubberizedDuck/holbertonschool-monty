#include "monty.h"

/**
 * error_empty_stack_pop - returns error if stack is empty
 * @line_number: line number error is occurring on
 */

int error_empty_stack_pop(int line_number)
{
	fprintf("L%d: can't pop an empty stack", line_number);
	return (EXIT_FAILURE);
}

/**
 * swap_error - exits and prints an error message if can't swap
 * @line_line: line number error is occurring on
 **/

void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
