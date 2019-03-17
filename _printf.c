#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf(const char *format, ...)
{
	int length = 0;

	printer_t printers[] = {
		{'c', print_char}
	};

	/*,
		{'i', print_int},
		{'s', print_string},
		{'d', print_double}, */	
	va_list arg;
	int i = 0, putchar_flag = 1, j;

	while (format[i] != '\0')
	{
		if (format[i] != '%' && putchar_flag)
			length += _putchar(format[i]);
		else
			putchar_flag = 0;
		if (!putchar_flag && format[i] != '%')
			for (j = 0; j < PRINTER_LENGTH; j++)
				if (printers[j].format == format[i])
				{
					length += printers[j].func(arg);
					putchar_flag = 1;
				}
		i++;
	}
	return (length);
}
