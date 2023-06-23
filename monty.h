#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MontyInterpreter - variables -args, file, line elements
 * @line: value
 * @file: pointer to monty file
 * @elements: line elements
 * @line_number: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct MontyInterpreter
{
	char *line;
	FILE *file;
	char *elements;
	int line_number;
} MontyInterpreter;
extern MontyInterpreter interpreter;

void *_realloc(void *ptr, size_t size);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int exec(char *element, stack_t **stack, unsigned int line_count, FILE *file);
void free_stack(stack_t *head);
void __push(stack_t **head, unsigned int line_number);
void __pall(stack_t **head, unsigned int line_number);
void addqueue(stack_t **head, int new_node);
void addnode(stack_t **head, int new_node);
void __pint(stack_t **head, unsigned int line_number);
void __pop(stack_t **head, unsigned int line_number);
void __swap(stack_t **head, unsigned int line_number);
void __add(stack_t **head, unsigned int line_number);
void __nop(stack_t **head, unsigned int line_number);
void __sub(stack_t **head, unsigned int line_number);
void __div(stack_t **head, unsigned int line_number);
void __mul(stack_t **head, unsigned int line_number);
void __mod(stack_t **head, unsigned int line_number);
void __pchar(stack_t **head, unsigned int line_number);
void __pstr(stack_t **head, unsigned int line_number);
void __rotl(stack_t **head, unsigned int line_number);
void __rotr(stack_t **head, unsigned int line_number);
void __stack(stack_t **head, unsigned int line_number);
void __queue(stack_t **head, unsigned int line_number);

#endif
