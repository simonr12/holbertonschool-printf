#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct checker - maps specifier to handler function
 * @type: format specifier (e.g. 'c', 's', '%')
 * @func: function to handle printing
 */
typedef struct checker
{
	char *type;
	int (*func)(va_list);
} checker;

int _printf(const char *format, ...);
int print_char(va_list list);
int print_string(va_list list);
int print_100(va_list list);

#endif
