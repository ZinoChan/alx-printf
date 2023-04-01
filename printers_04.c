#include "main.h"

/**
* print_S - print non printable characters
* @args: string argument
* @buffer: The buffer to write the number to.
* @buffer_index: A pointer to an index in the buffer to write to.
* Return: bytes printed
**/
int print_S(va_list args, char *buffer, int *buffer_index)
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
			_write('\\', buffer, buffer_index);
			_write('x', buffer, buffer_index);
			count += 2;

			if (str[i] > 0 && str[i] < HEX_BASE)
			{
				_write('0', buffer, buffer_index);
				count++;
			}
			count += print_unsigned_hex(str[i], 1, buffer, buffer_index);
		}
		else
		{
			_write(str[i], buffer, buffer_index);
			count++;
		}
	}
	return (count);
}


/**
* print_p - print pointer address
* @args: pointer arguments
* @buffer: The buffer to write the number to.
* @buffer_index: A pointer to an index in the buffer to write to.
* Return: number of bytes printed
**/
int print_p(va_list args, char *buffer, int *buffer_index)
{
	unsigned long int n;
	int count = 0;

	n = va_arg(args, unsigned long int);

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	_write('0', buffer, buffer_index);
	_write('x', buffer, buffer_index);
	count += print_unsigned_hex(n, 0, buffer, buffer_index) + 2;
	return (count);
}



