#include "main.h"

/**
 * _printf - function like printf
 * @format: string whit format to print
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	int char_printed = 0;
	va_list args;
	int (*sp_func)(va_list);

	va_start(args, format);

	if (!format)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			sp_func = get_sp_func(format);
			if (!sp_func)
			{
				char_printed += write(1, "%", 1);
				if (*format)
					char_printed += write(1, format, 1);
			}
			else
				char_printed += sp_func(args);
		}
		else
			char_printed += write(1, format, 1);
		format++;
	}

	va_end(args);
	return (char_printed);
}
