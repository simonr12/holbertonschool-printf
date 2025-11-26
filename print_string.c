#include "main.h"
#include <unistd.h>

int print_string(va_list list)
{
	char *s = va_arg(list, char *);
	int len = 0;

	if (!s)
		s = "(null)";

	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}
