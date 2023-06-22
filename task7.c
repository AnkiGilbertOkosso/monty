#include "monty.h"

/**
 * __div - divides the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/

void __div(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack = *head;
	if (stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = stack->next->n / stack->n;
	stack->next->n = num;
	*head = stack->next;
	free(stack);
}
