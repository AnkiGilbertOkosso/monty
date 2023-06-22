#include "monty.h"

/**
 * __swap - adds a top two elements of a stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void __swap(stack_t **head, unsigned int line_number)
{
	stack_t *stack;
	int len = 0, num;

	stack = *head;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack = *head;
	num = stack->n;
	stack->n = stack->next->n;
	stack->next->n = num;
}
