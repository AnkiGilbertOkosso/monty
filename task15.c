#include "monty.h"
/**
 * __stack - prints a top
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void __stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	interpreter.line_number = 0;
}

/**
 * __queue - prints the top
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void __queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	interpreter.line_number = 1;
}
