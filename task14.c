#include "monty.h"
/**
  *__rotr- rotates the stack to the bottom
  *@head: stack head
  *@line_number: line_number
  *Return: no return
 */
void __rotr(stack_t **head, unsigned int line_number)
{
	stack_t *stack;

	(void)line_number;

	stack = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (stack->next)
		stack = stack->next;

	stack->next = *head;
	stack->prev->next = NULL;
	stack->prev = NULL;
	(*head)->prev = stack;
	(*head) = stack;
}
