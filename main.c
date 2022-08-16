#include "monty.h"

int check_command(char *line, unsigned int line_num, stack_t *head)
{
	int i, n;
	char *arr[2];

	instruction_t check[] = {
		{"push", _push},
		{NULL, NULL}
	};

	arr[0] = strtok(line, " ");
	printf("arr[0]: %s\n", arr[0]);
	i = 0;
	while (check[i].opcode != NULL)
	{
		printf("i:%d\n", i);
		if (check[i].opcode == arr[0])
			check[i].f(&head, line_num);
		i++;
	}
	if (strcmp(arr[0], "push") == 0)
	{
		arr[1] = strtok(NULL, " ");
		printf("arr[1]: %s\n", arr[1]);
		if ((n = atoi(arr[1])) == 0)
		{
			invalid_instruction(line_num, arr[0]);
		}
		head->n = n;
		printf("n: %d\n", n);
	}

	return (0);
}

int main(int argc, char *argv[])
{
	unsigned int line_num = 1;
	char *line;
	size_t len = 0;
	ssize_t nread;
	FILE *stream;
	stack_t *head;

	if (argc != 2)
		usage_err();

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		usage_err();

	head = NULL;

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		printf("line: %s\n", line);
		check_command(line, line_num, head);
		line_num++;
	}

	return (0);
}
