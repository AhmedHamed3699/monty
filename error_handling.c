#include "monty.h"

/**
 * print_error - printing error to stderr
 * @line_number: line number
 * @message: message string
 * @addition: an additional string
 *
 * Return: void
 */
void print_error(unsigned int line_number, char *message, char *addition)
{
    if (addition)
        fprintf(stderr, "L%i: %s %s\n", line_number, message, addition);
    else
        fprintf(stderr, "L%i: %s\n", line_number, message);
    exit(EXIT_FAILURE);
}

/**
 * print_errorMessage - printing error message to stderr
 * @message: message string
 * @addition: an additional string
 * 
 * Return: void
 */
void print_errorMessage(char *message, char *addition)
{
    if (addition)
        fprintf(stderr, "%s %s\n", message, addition);
    else
        fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}