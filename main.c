#include "monty.h"

int check_command(char *command, unsigned int line_num, stack_t **head)
{
	int i;
	instruction_t check[] = {
		{"push", _push},
		{"pall", _pall},
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
		if (command == NULL)
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
