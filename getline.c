#include "monty.h"

/**
 * getline - Read a line from a stream and store
 * it in a dynamically allocated buffer.
 *
 * @lineptr: Pointer to the buffer that will store the line.
 * @n: Pointer to the size of the buffer.
 * @stream: The input stream to read from.
 *
 * Return: Number of characters read (excluding null terminator),
 * or -1 on failure or EOF.
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer = NULL;
	int c;
	char *temp;
	ssize_t num_chars = 0;
	size_t bufsize = 0;


	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	buffer = (char *)malloc(bufsize + 1);
	if (buffer == NULL)
		return (-1);

	while ((c = getc(stream)) != EOF && c != '\n')
	{
		buffer[num_chars++] = c;
		if (num_chars == (ssize_t)bufsize)
		{
			bufsize += 64;
			temp = (char *)_realloc(buffer, bufsize + 1);
			if (temp == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = temp;
		}
	}
	if (num_chars == 0 && c == EOF)
	{
		free(buffer);
		return (-1);
	}
	buffer[num_chars] = '\0';
	*lineptr = buffer;
	*n = num_chars;

	return (num_chars);
}

/**
 * _realloc - reallocates memory block
 * @ptr: pointer to the prev memory allocated
 * @old_size: size of the allocated space of ptr
 * @new_size: new size of the new memory block
 * Return: ptr
 */

void *_realloc(void *ptr, size_t size)
{
	size_t copy_size;
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		copy_size = size;
		if (size > sizeof(ptr))
			copy_size = sizeof(ptr);

		memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}
