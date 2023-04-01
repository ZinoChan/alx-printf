#include "main.h"


/**
 * get_digit_count - calc the number of digits in a number
 * @num: number
 * @base: number base
 * Return: Number of digits in number
 */
int get_digit_count(unsigned long int num, unsigned int base)
{
	int count = 1;

	while (num >= base)
	{
		num /= base;
		count++;
	}
	return (count);
}

/**
 * write_number - write every digit of number
 * @num: number
 * @base: number base
 * Return: void
 */
void write_number(unsigned int num, unsigned int base)
{
	if (num >= base)
		write_number(num / base, base);
	_write('0' + (num % base));
}

/**
 * print_unsigned_hex - print hex of uns integer
 * @num: number to print
 * @uppr: if hex is upper 0 else 1
 * Return: Number of digits printed
 */
int print_unsigned_hex(unsigned long int num, int uppr)
{
	int count = 0, i;
	int digit_count = get_digit_count(num, HEX_BASE);
	char *hex_digits = uppr ? UPPR_HEX : LWR_HEX;
	char *ptr = malloc(sizeof(char) * digit_count);

	if (ptr == NULL)
		return (-1);

	if (num < 1)
	{
		_write('0');
		return (1);
	}

	for (i = digit_count - 1; i >= 0; i--)
	{
		ptr[i] = hex_digits[num % HEX_BASE];
		num /= HEX_BASE;
		count++;
	}

	for (i = 0; i < digit_count; i++)
		_write(ptr[i]);
	free(ptr);
	return (count);
}


