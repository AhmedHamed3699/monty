#include "monty.h"

/**
 * pchar_op - prints the char at the top of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	int data;

	if (!top(stack, &data))
		print_error(stack, line_number, "can't pchar, stack empty", NULL);
	if (data < 0 || data > 127)
		print_error(stack, line_number, "can't pchar, value out of range", NULL);
	printf("%c\n", data);
}

/**
 * pstr_op - prints the string starting at the top of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	int data;
	stack_t *tmpStack = NULL;
	(void)line_number;

	while (pop(stack, &data))
	{
		push(&tmpStack, data);
		if (data <= 0 || data > 127)
			break;
		printf("%c", data);
	}
	putchar('\n');
	while (pop(&tmpStack, &data))
		push(stack, data);
}
