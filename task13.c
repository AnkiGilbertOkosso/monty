#include "monty.h"
/**
  *__rotl- rotate the stack to the top
  *@head: stack head
  *@line_number: line_number
  *Return: no return
 */
void __rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head, *stack;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
		return;

	stack = (*head)->next;
	stack->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = stack;
}
