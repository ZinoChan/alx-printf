#include "main.h"

/**
 * get_sp_func - selects the correct function to perform
 * the formating asked by the user.
 * @format: char specifier.
 *
 * Return: pointer to the function that corresponds to the specifier.
 */

int (*get_sp_func(const char *format))(va_list)
{
	print_t sps[] = {
		{"c", print_chr},
		{"s", print_str},
		{"%", print_percent},
		{NULL, NULL}
	};
	int i = 0;

	while (sps[i].sp != NULL)
	{
		if (*(sps[i].sp) == *format)
			return (sps[i].f);
		i++;
	}
	return (NULL);
}
