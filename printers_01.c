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
    int i = 0;
    int num = va_arg(args, int);
    unsigned int abs, divisor = 1;

    if (num < 0) {
        _write('-');
        abs = -num;
        i = 1;
    } else {
        abs = num;
    }

    while (abs / divisor > 9) {
        divisor *= 10;
    }

    while (divisor != 0) {
        _write('0' + abs / divisor);
        abs %= divisor;
        divisor /= 10;
        i++;
    }

    return i;

}






