#include "monty.h"
/**
 * __push - add node to a stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void __push(stack_t **head, unsigned int line_number)
{
	int num, i = 0, f = 0;

	if (interpreter.line)
	{
		if (interpreter.line[0] == '-')
			i++;
		for (; interpreter.line[i] != '\0'; i++)
		{
			if (interpreter.line[i] > 57 || interpreter.line[i] < 48)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(interpreter.file);
			free(interpreter.elements);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(interpreter.file);
		free(interpreter.elements);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	num = atoi(interpreter.line);
	if (interpreter.line_number == 0)
		addnode(head, num);
	else
		addqueue(head, num);
}

/**
 * __pall - prints the stack
 * @head: stack head
 * @line_number: no used
 * Return: no return
*/

void __pall(stack_t **head, unsigned int line_number)
{
	stack_t *stack;
	(void)line_number;

	stack = *head;
	if (stack == NULL)
		return;
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
