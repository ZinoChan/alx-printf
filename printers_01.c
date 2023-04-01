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
	int count = 0;
	int n = va_arg(args, int);

	if (n < 0)
	{
		_write('-');
		n = -n;
		count++;
	}
	count += recursive_print(n);
	return (count);
}

/**
  * recursive_print - Prints a integer
  * @n: integer to print
  * Return: Nothing
  */
int recursive_print(int n)
{
	if (n / 10)
		return (1 + recursive_print(n / 10));

	_write((n % 10) + '0');
	return (1);
}
