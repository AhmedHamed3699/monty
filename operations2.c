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

/**
 * rotl_op - rotates the stack to the top
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	int data, first_element;
	stack_t *tmpStack = NULL;
	(void)line_number;

	if (!pop(stack, &first_element))
		return;
	while (pop(stack, &data))
		push(&tmpStack, data);
	push(stack, first_element);
	while (pop(&tmpStack, &data))
		push(stack, data);
}

/**
 * rotr_op - rotates the stack to the bottom
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	int data, last_element;
	stack_t *tmpStack = NULL;
	(void)line_number;

	while (pop(stack, &data))
		push(&tmpStack, data);
	if (!pop(&tmpStack, &last_element))
		return;
	while (pop(&tmpStack, &data))
		push(stack, data);
	push(stack, last_element);
}
