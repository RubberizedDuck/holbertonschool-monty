#include "monty.h"

int check_command(char *line, int line_num)
{
	char *command;
	int n, idx;
	stack_t *head = NULL;
	instruction_t check[] = {
		{"push", _push},
		{"pall", pall},
		{NULL, NULL};
	};
	command = strtok(line, " ");

	idx = 0;
	while (check[idx].opcode != NULL)
	{
		if (*(check[idx].opcode) == command)
		{
			check[idx].f(&head, line_num);
		}
		idx++;
	}

	
}

int main(int argc, char *argv[])
{
	char *file, *stored, *line;
	int filedes, file_read, line_num = 1;

	if (argc != 2)
		usage_err();
	file = argv[1];

	filedes = open(file, O_RDONLY);
	if (filedes == -1)
		usage_err();

	stored = malloc(sizeof(*stored) * 1024);
	if (stored == NULL)
		exit(1);

	file_read = read(filedes, stored, 1024);
	if (file_read == -1)
	{
		free(stored);
		return (0);
	}

	line = strtok(stored, "\n");
	while (line != NULL)
	{
		if (check_command(line, line_num) == 0)
			line_num++;
		line = strtok(NULL, "\n");
	}

	printf("file:%s\n", stored);

	return (0);
}
