#include "main.h"


/**
  * print_binary - Prints a int converted to binary
  * @args: A list of variadic arguments
  *
  * Return: The number of printed digits
  */

int print_binary(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		_write('1');
		n = -n;
		count++;
	}

	count += print_binary_helper(n);
	return (count);
}

/**
 * print_binary_helper - Prints the binary format of a given number
 * @n: The number to convert
 *
 * Return: The number of printed digits
 */
int print_binary_helper(int n)
{
	int count;

	if (n <= 1)
	{
		_write(n + '0');
		return (1);
	}

	count = print_binary_helper(n / 2);
	_write((n % 2) + '0');

	return (count + 1);
}


/**
 * print_uns_int - prints unsigned integer
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */

int print_uns_int(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int digit_count = get_digit_count(n, 10);

	if (n == 0)
	{
		_write('0');
		return (1);
	}

	write_number(n, 10);
	return (digit_count);
}

/**
 * print_octal - prints unsigned octal
 * @args: arguments list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int digit_count = get_digit_count(n, OCTAL_BASE);

	if (n == 0)
	{
		_write('0');
		return (1);
	}

	write_number(n, 8);

	return (digit_count);
}



