#include "monty.h"


/**
* main - monty code interpreter
* @argc: number of the arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char *line;
	FILE *file;
	size_t line_size = 0;
	ssize_t chars_read = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	interpreter.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (chars_read > 0)
	{
		line = NULL;
		chars_read = getline(&line, &line_size, file);
		interpreter.elements = line;
		line_number++;

		if (chars_read > 0)
			exec(line, &stack, line_number, file);

		free(line);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
