#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Custom printf implementation
 * @format: Format string containing the characters and format specifiers
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list arg_list;
    int i = 0;
    int len = 0;

    if (format == NULL)
    {
        return (-1);
    }
    va_start(arg_list, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] == '%') // PErcent charater
            {
                putchar('%');
                i += 2;
                len++;
            }
        else if (format[i] == '%' && format[i + 1] == 'c') //Print character
        {
            char c = (char)va_arg(arg_list, int);
            putchar(c);
            i += 2;
            len++;
        }
        else if (format[i] == '%' && format[i + 1] == 's') // Print strings
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
        else
        {
            putchar(format[i]);
            i++;
            len++;
        }
    }

    va_end(arg_list);
    return (len); // Length of the format string
}
