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

    data = atoi(args);
    if (!args || (args[0] != '0' && !data))
        print_error(line_number, "usage: push integer");
    
    push(stack, data);
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
    stack_t *tmpStack;
    (void) line_number;

    while(!pop(stack, &data))
    {
        push(&tmpStack, data);
        printf("%i\n", data);
    }
    while(!pop(&tmpStack, &data))
        push(stack, data);
}