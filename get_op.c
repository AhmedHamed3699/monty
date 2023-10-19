#include "monty.h"

/**
 * get_op - get function that corresponds
 * to the specified opcode
 * @op: operation code
 *
 * Return: pointer to needed function
 */
void (*get_op(char *op))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t i_t[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{NULL, NULL}
	};

	while (i_t[i].opcode != NULL)
	{
		if (!strcmp(i_t[i].opcode, op))
			return (i_t[i].f);
		i++;
	}
	return (NULL);
}
