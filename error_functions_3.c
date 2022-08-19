#include "monty.h"

/**
 * pchar_error - prints a message to the STDERR if pchar can not
 * execute properly
 * @line_number: count of lines that have been executed
 * @mode: determine which message to print
 * Return: int
 */

int pchar_error(unsigned int line_number, int mode)
{
	if (mode == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
	}
	else
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
	exit(EXIT_FAILURE);
}
