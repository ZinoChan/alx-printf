#include "main.h"

/**
* get_sp_func- get the correct function
* @format: format specifier
* Return: pointer to the correct function
**/

int (*get_sp_func(char format))(va_list, char *buffer, int *buffer_index)
{
	int i;
		print_t sp[] = {
		{'c', print_chr},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_uns_int},
		{'o', print_octal},
		{'x', print_uns_hex},
		{'X', print_uns_HEX},
		{'S', print_S},
		{'p', print_p},
		{'\0', NULL}
	};

	for (i = 0; sp[i]._type; i++)
	{
		if (format == sp[i]._type)
		{
			return (sp[i].f);
		}
	}
	return (NULL);
}
