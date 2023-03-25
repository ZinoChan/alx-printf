#include "main.h"

/**
 * print_str - Prints a string to stdout
 * @args: A va_list containing the string to print
 * Return: The number of characters printed
 */
int print_str(va_list args)
{
	int count = 0;
	char *s = va_arg(args, char *);

	if (!s)
		s = "(null)";

	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);

}
