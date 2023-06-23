#include "monty.h"
/**
 * __pstr - prints a string starting at the top of a stack,
 * followed by the new
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void __pstr(stack_t **head, unsigned int line_number)
{
	stack_t *stack;
	(void)line_number;

	stack = *head;
	while (stack)
	{
		if (stack->n > 127 || stack->n <= 0)
		{
			break;
		}
		printf("%c", stack->n);
		stack = stack->next;
	}
	printf("\n");
}
