#include "main.h"


/**
  * print_binary - Prints a int converted to binary
  * @args: A list of variadic arguments
  * @buffer: The buffer to write the number to.
  * @buffer_index: A pointer to an index in the buffer to write to.
  * Return: The number of printed digits
  */

int print_binary(va_list args, char *buffer, int *buffer_index)
{
	unsigned int num = va_arg(args, int);
	int count = 0;

	if (num < 1)
	{
		_write('0' + 0, buffer, buffer_index);
		return (1);
	}
	count = get_digit_count(num, 2);
	write_number(num, 2, buffer, buffer_index);
	return (count);
}

/**
 * print_binary_helper - Prints the binary format of a given number
 * @n: The number to convert
 * @buffer: The buffer to write the number to.
 * @buffer_index: A pointer to an index in the buffer to write to.
 * Return: The number of printed digits
 */
int print_binary_helper(int n, char *buffer, int *buffer_index)
{
	int count;

	if (n <= 1)
	{
		_write(n + '0', buffer, buffer_index);
		return (1);
	}

	count = print_binary_helper(n / 2, buffer, buffer_index);
	_write((n % 2) + '0', buffer, buffer_index);

	return (count + 1);
}


/**
 * print_uns_int - prints unsigned integer
 * @args: arguments list containing the integer to print
 * @buffer: The buffer to write the number to.
 * @buffer_index: A pointer to an index in the buffer to write to.
 * Return: Number of characters printed
 */

int print_uns_int(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n = va_arg(args, unsigned int);
	int digit_count = get_digit_count(n, 10);

	if (n == 0)
	{
		_write('0', buffer, buffer_index);
		return (1);
	}

	write_number(n, 10, buffer, buffer_index);
	return (digit_count);
}

/**
 * print_octal - prints unsigned octal
 * @args: arguments list containing the integer to print
 * @buffer: The buffer to write the number to.
 * @buffer_index: A pointer to an index in the buffer to write to.
 * Return: Number of characters printed
 */
int print_octal(va_list args, char *buffer, int *buffer_index)
{
	unsigned int n = va_arg(args, unsigned int);
	int digit_count = get_digit_count(n, OCTAL_BASE);

	if (n == 0)
	{
		_write('0', buffer, buffer_index);
		return (1);
	}

	write_number(n, 8, buffer, buffer_index);

	return (digit_count);
}



