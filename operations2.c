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
	push(stack, e2 + e1);
}

/**
 * sub_op - subtracts the top two elements of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	int e1, e2;

	if (!pop(stack, &e1) || !pop(stack, &e2))
		print_error(stack, line_number, "can't sub, stack too short", NULL);
	push(stack, e2 - e1);
}

/**
 * div_op - divides the top two elements of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int e1, e2;

	if (!pop(stack, &e1) || !pop(stack, &e2))
		print_error(stack, line_number, "can't div, stack too short", NULL);
	if (e1 == 0)
		print_error(stack, line_number, "division by zero", NULL);
	push(stack, e2 / e1);
}

/**
 * mul_op - multiplies the top two elements of the stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	int e1, e2;

	if (!pop(stack, &e1) || !pop(stack, &e2))
		print_error(stack, line_number, "can't mul, stack too short", NULL);
	push(stack, e2 * e1);
}

/**
 * mod_op - computes the rest of division of the top two elements of stack
 * @stack: the stack
 * @line_number: line number
 *
 * Return: void
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	int e1, e2;

	if (!pop(stack, &e1) || !pop(stack, &e2))
		print_error(stack, line_number, "can't mod, stack too short", NULL);
	if (e1 == 0)
		print_error(stack, line_number, "division by zero", NULL);
	push(stack, e2 % e1);
}
