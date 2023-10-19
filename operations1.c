#include "monty.h"

/**
 * push_op - push operation
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	int data;
	char *args = strtok(NULL, " ");

	data = atoi(args);
	if (!args || (args[0] != '0' && !data))
		print_error(stack, line_number, "usage: push integer", NULL);
	push(stack, data);
	if (format)
		rotl_op(stack, line_number);
}

/**
 * pall_op - prints all the values on the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	int data;
	stack_t *tmpStack = NULL;
	(void)line_number;

	while (pop(stack, &data))
	{
		push(&tmpStack, data);
		printf("%i\n", data);
	}
	while (pop(&tmpStack, &data))
		push(stack, data);
}


/**
 * pint_op - prints value on the top of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	int data;

	if (!top(stack, &data))
		print_error(stack, line_number, "can't pint, stack empty", NULL);
	printf("%i\n", data);
}

/**
 * pop_op - removes the top element of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	int data;

	if (!pop(stack, &data))
		print_error(stack, line_number, "can't pop an empty stack", NULL);
}

/**
 * swap_op - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	int e1, e2;

	if (!pop(stack, &e1) || !pop(stack, &e2))
		print_error(stack, line_number, "can't swap, stack too short", NULL);
	push(stack, e1);
	push(stack, e2);
}
