#include "main.h"

/**
  * _print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the format
  */
int _print_format(const char *format, va_list args, char *buffer, int *buffer_index)
{
	int (*sp_func)(va_list, char *buffer, int *buffer_index);
	int count = 0, i, num_flags;
	char flags[6];

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0' ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
			{
				num_flags = handle_flag(&format[i + 1], flags);
				i += num_flags;
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
				buffer[*buffer_index] = format[i];
				(*buffer_index)++;
				count++;
				i++;
			}
		}
		else
		{
			buffer[*buffer_index] = format[i];
			(*buffer_index)++;
			count++;
		}
		if (*buffer_index >= 1024)
		{
			write(1, buffer, 1024);
			count+= 1024;
			*buffer_index = 0;
		}
	}
	va_end(args);
	return (count);
}
