#include "main.h"

/**
  * _print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the format
  */
int _print_format(const char *format, va_list args)
{
	int (*sp_func)(va_list);
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
					_write(format[i]);
					count++;
				}
				else
				{
					count = count + sp_func(args);
					i++;
				}
			}
			else
			{
				_write(format[i]);
				count++;
				i++;
			}
		}
		else
		{
			_write(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
