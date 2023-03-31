#include "main.h"

/**
 * print_uns_hex - Prints unsigned hex
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_hex(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_unsigned_hex(n, 0, buffer, buffer_index));
}


/**
 * print_uns_HEX - Prints unsigned HEX
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_HEX(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_unsigned_hex(n, 1, buffer, buffer_index));
}
