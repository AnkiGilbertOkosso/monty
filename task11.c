#include "monty.h"
/**
 * __pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void __pchar(stack_t **head, unsigned int line_number)
{
	stack_t *stack;

	stack = *head;
	if (!stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (stack->n > 127 || stack->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", stack->n);
}
