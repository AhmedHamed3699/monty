#include "monty.h"

/**
 * print_error - printing error to stderr
 * @line_number: line number
 * @message: message string
 *
 * Return: void
 */
void print_error(unsigned int line_number, char *message)
{
    fprintf(stderr, "L%i: %s", line_number, message);
    exit(EXIT_FAILURE);
}

/**
 * print_memoryError - printing memory error to stderr
 * Return: void
 */
void print_memoryError()
{
    fprintf(stderr, "Error: malloc failed");
    exit(EXIT_FAILURE);
}