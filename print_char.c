#include "main.h"
#include <unistd.h>

int print_char(va_list list)
{
	char c = va_arg(list, int);

	return (write(1, &c, 1));
}
