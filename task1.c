#include "monty.h"

/**
 * __pint - prints a top
 * @head: stack head
 * @line_number: line_number
 * Return: Nothing
 */

void __pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(interpreter, file);
		free(interpreter, elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
