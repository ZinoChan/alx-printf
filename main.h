#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct sp - Struct print_t
 * @sp: The specifier
 * @f: The function associated
 */
typedef struct sp
{
	char *sp;
	int (*f)(va_list);
} print_t;

int print_chr(va_list);
int print_percent(va_list);
int print_str(va_list);
int (*get_sp_func(const char *format))(va_list);
int _printf(const char *format, ...);


#endif
