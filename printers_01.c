#include "main.h"
void print_digits(int number, int count, int is_negative);
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
	int num = va_arg(args, int);
	int i = 0, j;

	if (num < 0)
	{
		_write('-');
		num = -num;
		i++;
	}
	if (num == 0)
	{
		_write('0');
		i++;
	} else
	{
		int digits[10];
		int count = 0;

		while (num != 0)
		{
			digits[count++] = num % 10;
			num /= 10;
		}
		for (j = count - 1; j >= 0; j--)
		{
			_write(digits[j] + '0');
			i++;
		}
	}
	return (i);
}


