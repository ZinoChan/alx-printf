#include "main.h"

/**
* print_S - print non printable characters
* @args: string argument
* Return: bytes printed
**/
int print_S(va_list args)
{
	unsigned int i, count = 0;
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_write('\\');
			_write('x');
			count += 2;

			if (str[i] > 0 && str[i] < HEX_BASE)
			{
				_write('0');
				count++;
			}
			count += print_unsigned_hex(str[i], 1);
		}
		else
		{
			_write(str[i]);
			count++;
		}
	}
	return (count);
}


/**
* print_p - print pointer address
* @args: pointer arguments
* Return: number of bytes printed
**/
int print_p(va_list args)
{
	unsigned long int n;
	int count = 0;

	n = va_arg(args, unsigned long int);

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	_write('0');
	_write('x');
	count += print_unsigned_hex(n, 0) + 2;
	return (count);
}



