#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf implementation
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, j, len = 0;

	checker printers[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_100},
		{NULL, NULL}
	};

	if (!format)
		return (-1);

	va_start(list, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;

			while (printers[j].type)
			{
				if (format[i + 1] == *(printers[j].type))
				{
					len += printers[j].func(list);
					i += 2;
					break;
				}
				j++;
			}

			/* If no valid specifier found */
			if (printers[j].type == NULL)
			{
				len += write(1, &format[i], 1);
				i++;
			}
		}
		else
		{
			len += write(1, &format[i], 1);
			i++;
		}
	}

	va_end(list);
	return len;
}
 