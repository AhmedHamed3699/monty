#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	unsigned int fd, line_number = 1, size = 0;
	ssize_t r = 1;
	char *inst = NULL, op;
	void (*instruction)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		print_errorMessage("USAGE: monty file", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_errorMessage("Error: Can't open file", argv[1]);

	r = read(fd, inst, size);
	while (r > 0)
	{
		op = strtok(inst, " ");
		if (op)
		{
			instruction = get_op(op);
		}
		free(inst);
		inst = NULL, r = read(fd, inst, size);
		line_number++;
	}
	free(inst);
	close(fd);
	return (EXIT_SUCCESS);
}