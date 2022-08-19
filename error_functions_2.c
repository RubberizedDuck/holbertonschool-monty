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


/**
 * sub_error - prints to STDERR if _sub function can't execute
 * @line_number: count of lines executed
 * Return: int
 */

int sub_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * div_error - prints to STDERR if _div func can't execute
 * @line_number: count of lines executed
 * @mode: determines which error to print
 * Return: int
 */

int div_error(unsigned int line_number, int mode)
{
	if (mode == 1)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
	}
	else
		fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * mod_error - prints to STDERR if _mod func can't execute
 * @line_number: count of lines executed
 * @mode: determines which error to print
 * Return: int
 */

int mod_error(unsigned int line_number, int mode)
{
	if (mode == 1)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
	}
	else
		fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
}
