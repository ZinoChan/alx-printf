#include "main.h"
/**
 * _printf - function my printf
 * @format: string whit format to print
 * Return: number of chars that print
 */
int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;
	char buffer[1024];
	int buff_idx = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	length = _print_format(format, args, buffer, &buff_idx);
	va_end(args);
	if (buff_idx > 0)
	{
		write(1, buffer, buff_idx);
		buff_idx = 0;
	}
	return (length);
}
