#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * _printf - Custom printf implementation
 * @format: Format string containing characters and format specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int i = 0;
	int len = 0;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	while (format[i] != '\0')
	{
		/* Print % character */
		if (format[i] == '%' && format[i + 1] == '%')
		{
			putchar('%');
			i += 2;
			len++;
		}
		/* Print character */
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c = (char)va_arg(arg_list, int);

			putchar(c);
			i += 2;
			len++;
		}
		/* Print string */
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *s = va_arg(arg_list, char *);

			if (s == NULL)
				s = "(null)";

			while (*s != '\0')
			{
				putchar(*s);
				s++;
				len++;
			}
			i += 2;
		}
		/* Print regular characters */
		else
		{
			putchar(format[i]);
			i++;
			len++;
		}
	}

	va_end(arg_list);
	return (len);
}
