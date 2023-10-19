#include "monty.h"

/**
 * print_error - printing error to stderr
 * @line_number: line number
 * @msg: message string
 * @addition: an additional string
 * @stack: the stack
 *
 * Return: void
 */
void print_error(stack_t **stack, int line_number, char *msg, char *addition)
{
	if (addition)
		fprintf(stderr, "L%i: %s %s\n", line_number, msg, addition);
	else
		fprintf(stderr, "L%i: %s\n", line_number, msg);
	free(cur_line);
	fclose(fp);
	freeAll(stack);
	exit(EXIT_FAILURE);
}

/**
 * print_errorMessage - printing error message to stderr
 * @msg: message string
 * @addition: an additional string
 * @stack: the stack
 *
 * Return: void
 */
void print_errorMessage(stack_t **stack, char *msg, char *addition)
{
	if (addition)
		fprintf(stderr, "%s %s\n", msg, addition);
	else
		fprintf(stderr, "%s\n", msg);
	free(cur_line);
	fclose(fp);
	freeAll(stack);
	exit(EXIT_FAILURE);
}

/**
 * print_fileError - printing any file error message to stderr
 * @msg: message string
 * @addition: an additional string
 *
 * Return: void
 */
void print_fileError(char *msg, char *addition)
{
	if (addition)
		fprintf(stderr, "%s %s\n", msg, addition);
	else
		fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
