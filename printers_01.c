#include "main.h"


/**
  * print_chr - Prints a char
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */
int print_chr(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

/**
  * print_str - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int print_str(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i]);
			i++;
		}

		return (i);
	}

	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}

/**
  * print_int - Prints a integer
  * @args: A list of variadic arguments
  * Return: The number of printed chars
  */
int print_int(va_list args)
{
	int num = va_arg(args, int), i = 0, digit;
	int is_negative = num < 0;
	unsigned int abs = is_negative ? -num : num;
	unsigned int divider = 1;

	if (abs <= 9)
	{
		_write(is_negative ? '-' : '0' + abs);
		return (1 + is_negative);
	}

	while (divider <= abs / 10)
		divider *= 10;

	if (is_negative)
		_write('-');

	while (divider > 0)
	{
		digit = abs / divider;
		_write('0' + digit);
		abs -= digit * divider;
		divider /= 10;
		i++;
	}

	return (i + is_negative);
}






