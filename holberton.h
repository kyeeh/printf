#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>

/**
 * struct printer - An structure for each format
 *
 * @format: character that represents the format
 * @func: function for each format
 */
typedef struct printer
{
	char format;
	int (*func)(va_list *);
} printer_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list *);
int print_string(va_list *);
int print_int(va_list *);
int print_unsigned_int(va_list *);
int print_double(va_list *);
int print_octal(va_list *);

#define PRINTER_LENGTH 5
#endif
