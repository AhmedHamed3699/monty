#include "monty.h"

/**
 * push - push an element to the stack
 * @stack: the stack
 * @data: data
 *
 * Return: pointer to the top if the stack, or NULL if something went wrong
 */
stack_t *push(stack_t **stack, int data)
{
	stack_t *newptr;

	if (!stack)
		return (NULL);

	newptr = malloc(sizeof(*newptr));
	if (!newptr)
		print_errorMessage(stack, "Error: malloc failed", NULL);
	newptr->n = data, newptr->prev = NULL, newptr->next = *stack;
	if (*stack)
		(*stack)->prev = newptr;
	*stack = newptr;
	return (newptr);
}

/**
 * pop - pops an element from the stack
 * @stack: the stack
 * @data: pointer to hold data value
 *
 * Return: 1 if successful, 0 otherwise
 */
int pop(stack_t **stack, int *data)
{
	stack_t *toDelete;

	if (!stack)
		return (0);

	toDelete = *stack;
	if (!toDelete)
		return (0);

	*stack = (*stack)->next;
	*data = toDelete->n;
	free(toDelete);
	if (*stack)
		(*stack)->prev = NULL;
	return (1);
}

/**
 * top - get the top element of the stack
 * @stack: the stack
 * @data: pointer to hold data value
 *
 * Return: 1 if successful, 0 otherwise
 */
int top(stack_t **stack, int *data)
{
	if (!stack || !(*stack))
		return (0);

	*data = (*stack)->n;
	return (1);
}

/**
 * empty - check if empty
 * @stack: the stack
 *
 * Return: 1 if empty, 0 not empty
 */
int empty(stack_t **stack)
{
	if (!stack || !(*stack))
		return (1);
	return (0);
}

/**
 * freeAll - free stack
 * @stack: the stack
 *
 * Return: void
 */
void freeAll(stack_t **stack)
{
	int data;

	if (!stack)
		return;
	while (pop(stack, &data))
		;
}
