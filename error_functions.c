#include "monty.h"

/**
 * usage_err - prints error if no file or more than one arg
 * was given
 * Return: EXIT_FAILURE always
 */
int usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - prints error if file for any reason, can't be opened
 * Return: EXIT_FAILURE always
 */
int open_file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction - prints the line number an error ocurred on
 * Return: EXIT_FAILURE always
 */
int invalid_instruction(int line_number, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints error if can't malloc anymore
 * Return: EXIT_FAILURE always
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * line_num_error - prints error if the value after push is not an integer
 * or there is no argument given
 * Return: EXIT_FAILURE always
 */
int line_num_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer", line_number);
	exit(EXIT_FAILURE);
}
