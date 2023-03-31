#include "main.h"

/**
  * print_chr - Prints a char
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */
int print_chr(va_list args, char *buffer, int *buffer_index)
{
	_write(va_arg(args, int), buffer, buffer_index);
	return (1);
}

/**
  * print_str - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int print_str(va_list args, char *buffer, int *buffer_index)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i], buffer, buffer_index);
			i++;
		}

		return (i);
	}

	_write('(', buffer, buffer_index);
	_write('n', buffer, buffer_index);
	_write('u', buffer, buffer_index);
	_write('l', buffer, buffer_index);
	_write('l', buffer, buffer_index);
	_write(')', buffer, buffer_index);
	return (6);
}

/**
  * print_int - Prints a integer
  * @args: A list of variadic arguments
  * Return: The number of printed chars
  */
int print_int(va_list args, char *buffer, int *buffer_index)
{
	int count = 0;
	int n = va_arg(args, int);

	if (n < 0)
	{
		_write('-', buffer, buffer_index);
		n = -n;
		count++;
	}
	count += recursive_print(n, buffer, buffer_index);
	return (count);
}

/**
  * recursive_print - Prints a integer
  * @n: integer to print
  * Return: Nothing
  */
int recursive_print(int n, char *buffer, int *buffer_index)
{
	if (n / 10)
		recursive_print(n / 10, buffer, buffer_index);

	_write((n % 10) + '0', buffer, buffer_index);
	return (1);
}
