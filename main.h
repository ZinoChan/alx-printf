#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define UPPR_HEX "0123456789ABCDEF"
#define LWR_HEX "0123456789abcdef"
#define HEX_BASE 16
#define OCTAL_BASE 8

/**
  * struct sp - Struct specifiers
  * @_type: type of The conversion specifier
  * @f: The function pointer
  */
typedef struct sp
{
	char _type;
	int (*f)(va_list args, char *buffer, int *buffer_index);
} print_t;

int (*get_sp_func(char format))(va_list, char *buffer, int *buffer_index);
int _write(char c, char *buffer, int *buffer_index);
int _printf(const char *format, ...);
int print_chr(va_list args, char *buffer, int *buffer_index);
int print_str(va_list args, char *buffer, int *buffer_index);
int _print_format(const char *format, va_list args,
char *buffer, int *buffer_index);
int print_uns_int(va_list args, char *buffer, int *buffer_index);
int print_octal(va_list args, char *buffer, int *buffer_index);
int print_uns_hex(va_list args, char *buffer, int *buffer_index);
int print_uns_HEX(va_list args, char *buffer, int *buffer_index);
int print_S(va_list args, char *buffer, int *buffer_index);
int print_p(va_list args, char *buffer, int *buffer_index);
int print_int(va_list args, char *buffer, int *buffer_index);
int recursive_print(int n, char *buffer, int *buffer_index);
int print_binary(va_list args, char *buffer, int *buffer_index);
int print_binary_helper(int n, char *buffer, int *buffer_index);
int is_printable(char *buffer, int *buffer_index);

/*Helpers*/
int get_digit_count(unsigned long int num, unsigned int base);
void write_number(unsigned int num, unsigned int base,
char *buffer, int *buffer_index);
int print_unsigned_hex(unsigned long int num, int uppr,
char *buffer, int *buffer_index);


#endif
