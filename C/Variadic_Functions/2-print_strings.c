#include "variadic_functions.h"

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list vina;
	char *str;

	va_start(vina, n);
	for (i = 0; i < n - 1; i++)
	{
		str = va_arg(vina, char *);
		if (separator)
		{
			if (!str)
				printf("(nil)%s", separator);
			else
				printf("%s%s", str, separator);
		}
		else
		{
			if (!str)
				printf("(nil)");
			else
				printf("%s", str);
		}
	}
	printf("%s", va_arg(vina, char *));
	va_end(vina);
	printf("\n");

}
