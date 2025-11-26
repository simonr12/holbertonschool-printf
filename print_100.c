#include "main.h"
#include <unistd.h>

int print_100(va_list list)
{
	(void)list;

	return (write(1, "%", 1));
}
