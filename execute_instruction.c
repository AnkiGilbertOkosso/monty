#include "monty.h"

/**
 * exec - executes the opcode
 * @stack: head linked list - stack
 * @line_count: line_counter
 * @file: pointer to monty file
 * @element: line element
 * Return: Nothing
 */

int exec(char *element, stack_t **stack, unsigned int line_count, FILE *file)
{
	instruction_t ints[] = {
		{"push", __push},
		{"pall", __pall},
		{"pint", __pint}, {"pop", __pop},
		{"swap", __swap}, {"sub", __sub},
		{"add", __add},	{"nop", __nop},
		{"div", __div}, {"mul", __mul},
		{"mod", __mod},
		{"pchar", __pchar},
		{"pstr", __pstr},
		{"rotr", __rotr},
		{"rotl", __rotl},
		{"stack", __stack},
		{"queue", __queue},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(element, " \n\t");
	if (op && op[0] == '#')
		return (0);
	interpreter.line = strtok(NULL, " \n\t");
		while (ints[i].opcode && op)
		{
			if (strcmp(op, ints[i].opcode) == 0)
			{
				ints[i].f(stack, line_count);
				return (0);
			}
			i++;		}
	if (op && ints[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_count, op);
		fclose(file);
		free(element);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * free_stack - frees a doubly linked list
 * @head: head of a stack
 */

void free_stack(stack_t *head)
{
	stack_t *stack;

	stack = head;
	while (head)
	{
		stack = head->next;
		free(head);
		head = stack;
	}
}
