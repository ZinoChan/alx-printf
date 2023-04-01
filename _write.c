#include "main.h"

/**
 * _write - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _write(char c, char *buffer, int *buffer_index)
{
	if(*buffer_index >= BUFFER_SIZE)
	{
		write(1, buffer, 1024);
		*buffer_index = 0;
	}
	buffer[*buffer_index] = c;
	(*buffer_index)++;
	return (1);
}


