#include "monty.h"

int check_command(char *line, int line_count)
{
	char *command;
	int n;
	instruction_t check[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL};
	};
	command = strtok(line, " ");
}

int main(int argc, char *argv[])
{
	char *file, *stored, *line;
	int filedes, file_read, line_count = 1;

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
		if (check_command(line) == 0)
			line_count++;
		line = strtok(NULL, "\n");
	}

	printf("file:%s\n", stored);

	return (0);
}
