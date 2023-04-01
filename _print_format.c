#include "main.h"

/**
  * _print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  * @buffer: The buffer to write the number to.
  * @buffer_index: A pointer to an index in the buffer to write to.
  * Return: The length of the format
  */
int _print_format(const char *format, va_list args,
char *buffer, int *buffer_index)
{
	int (*sp_func)(va_list, char *buffer, int *buffer_index);
	int count = 0, i;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0' ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
			{
				sp_func = get_sp_func(format[i + 1]);
				if (sp_func == NULL)
				{
					buffer[*buffer_index] = format[i];
					(*buffer_index)++;
					count++;
				}
				else
				{
					count += sp_func(args, buffer, buffer_index);
					i++;
				}
			}
			else
			{
				buffer[*buffer_index] = format[i], (*buffer_index)++;
				count++, i++;
			}
		}
		else
		{
			buffer[*buffer_index] = format[i];
			(*buffer_index)++;
			count++;
		}
		count += is_printable(buffer, buffer_index);
	}
	va_end(args);
	return (count);
}


/**
  * is_printable - Prints the buffer when it's full
  * @buffer: The buffer to write the number to.
  * @buffer_index: A pointer to an index in the buffer to write to.
  * Return: The length of the printed chars
  */

int is_printable(char *buffer, int *buffer_index)
{
	if (*buffer_index >= BUFFER_SIZE)
	{
		write(1, buffer, BUFFER_SIZE);
		*buffer_index = 0;
		return (BUFFER_SIZE);
	} else
		return (0);
}
