#include "monty.h"




void get_func(char *opcode, int line_number)
{
	int index = 0, flag;

	instruction_t func_list [] = {
		{"push", /* insert func */},
		{"pall", /* insert func */},
		{"pop", /* insert func */},
		{"swap", /* insert func */},
		{"add", /* insert func */},
		{"nop", /* insert func */},
		{NULL, NULL}
	};

	while (func_list[index].opcode != NULL)
	{
		flag = 1;
		if (strcmp(opcode, func_list[index].opcode) == 0)
		{
			/* return value of functionassociated with string */;
			flag = 0;
		}
		index++;
	}
	if (flag == 1)
	{
		invalid_instruction(line_number, opcode);
		/* possibly free stored opcode */
	}
}
