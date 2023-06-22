#include "monty.h"

/**
  *__sub- sustration
  *@head: stack head
  *@line_number: line_number
  *Return: no return
 */

void __sub(stack_t **head, unsigned int line_number)
{
	stack_t *stack;
	int len, num;

	stack = *head;
	for (len = 0; stack != NULL; len++)
		stack = stack->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack = *head;
	num = stack->next->n - stack->n;
	stack->next->n = num;
	*head = stack->next;
	free(stack);
}
