#include "monty.h"

/**
 * add_op - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	int e1, e2;

	if (!pop(stack, &e1) || !pop(stack, &e2))
		print_error(stack, line_number, "can't add, stack too short", NULL);
	push(stack, e1 + e2);
}
