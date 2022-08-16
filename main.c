#include "monty.h"

int check_command(char *line, unsigned int line_num, stack_t **head)
{
	char *command;
	int i;
	instruction_t check[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	command = strtok(line, " \n\t\r");
	if (command == NULL)
		return (1);
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
	char *line;
	size_t len = 0;
	ssize_t nread;
	FILE *stream;
	stack_t *head = NULL;
	if (argc != 2)
		usage_err();

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		usage_err();

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		check_command(line, line_num, &head);
		line_num++;
	}

	return (0);
}
