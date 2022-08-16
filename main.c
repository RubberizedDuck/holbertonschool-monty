#include "monty.h"

int main(int argc, char *argv[])
{
	char *file, *stored;
	int filedes, file_read;

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

	printf("file:%s\n", stored);

	return (0);
}
