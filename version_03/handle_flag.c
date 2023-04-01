/**
 * handle_flag - Handles the flag characters for non-custom conversion specifiers
 * @format: The format string
 * @flag: The flag character to handle
 *
 * Return: The length of the flag string
 */

int handle_flag(const char *format, char *flags)
{
	int i = 0, num_flags = 0;

	while (format[i] == '+' || format[i] == ' ' || format[i] == '#' ||
           format[i] == '0' || format[i] == '-')
	{
		flags[num_flags] = format[i];
		num_flags++;
		i++;
	}

	flags[num_flags] = '\0';

	return (num_flags);
}