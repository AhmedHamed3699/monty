#include "monty.h"

FILE *fp;
char *cur_line;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	size_t line_number = 1, size = 0;
	ssize_t r = 1;
	char *op;
	stack_t *stack = NULL;
	void (*instruction)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		print_fileError("USAGE: monty file", NULL);
	fp = fopen(argv[1], "r");
	if (!fp)
		print_fileError("Error: Can't open file", argv[1]);

	cur_line = NULL, r = getline(&cur_line, &size, fp);
	while (r > 0)
	{
		cur_line[strlen(cur_line) - 1] = '\0';
		op = strtok(cur_line, " ");
		if (op && strcmp(op, "nop") && op[0] != '#')
		{
			instruction = get_op(op);
			if (instruction == NULL)
				print_error(&stack, line_number, "unknown instruction", op);
			instruction(&stack, line_number);
		}
		free(cur_line);
		cur_line = NULL, r = getline(&cur_line, &size, fp);
		line_number++;
	}
	free(cur_line);
	fclose(fp);
	freeAll(&stack);
	return (EXIT_SUCCESS);
}
