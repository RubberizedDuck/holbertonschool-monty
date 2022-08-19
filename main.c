#include "monty.h"

/**
 * check_command - checks the opcode against the command sent through
 * @command: pointer to command
 * @line_num: count of lines executed
 * @head: pointer to start of stack
 * Return: 0 on success, 1 on failure
 */

int check_command(char *command, unsigned int line_num, stack_t **head)
{
	int i;
	instruction_t check[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	i = 0;
	while (check[i].opcode != NULL)
	{
		if (strcmp(check[i].opcode, command) == 0)
		{
			check[i].f(head, line_num);
			return (0);
		}
		i++;
	}
	invalid_instruction(line_num, command);

	return (1);
}

/**
 * main - entry into program
 * @argc: count of args passed
 * @argv: pointer to array of args passed
 * Return: 0 on success, exit other wise
 */

int main(int argc, char *argv[])
{
	unsigned int line_num = 1;
	char *line, *command;
	size_t len = 0;
	ssize_t nread;
	FILE *stream;
	stack_t *head = NULL;

	if (argc != 2)
		usage_err();

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		open_file_error(argv[1]);

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		command = strtok(line, " \n\t\r");
		if (command == NULL || command[0] == '#')
		{
			line_num++;
			continue;
		}
		glob_var.argument = strtok(NULL, " \n\t\r");
		check_command(command, line_num, &head);
		line_num++;
	}
	free(line);
	fclose(stream);
	free_dlist(&head);
	return (0);
}
