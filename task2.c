#include "monty.h"

/**
 * __pop - prints a top
 * @head: stack head
 * @line_number: line_number
 * Return: Nothing
 */

void __pop(stack_t **head, unsigned int line_number)
{
	stack_t *stack;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack = *head;
	*head =  stack->next;
	free(stack);
}
