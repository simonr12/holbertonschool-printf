#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;
	char *s;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			putchar('%'), i += 2, len++;
		else if (format[i] == '%' && format[i + 1] == 'c')
			putchar(va_arg(args, int)), i += 2, len++;
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = va_arg(args, char *);
			if (!s)
				s = "(null)";
			while (*s)
				putchar(*s++), len++;
			i += 2;
		}
		else
			putchar(format[i]), i++, len++;
	}

	va_end(args);
	return (len);
}
