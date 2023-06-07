#include "main.h"

void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

void print_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

void print_str(va_list arg)
{
	char *str = va_arg(arg, char*);

	if (str == NULL)
		str = "(nil)";

	printf("%s", str);
}

void print_all(const char * const format, ...)
{
	va_list list;
	int i, j;
	funcsymbol array[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_str}
	};
	char *sep = NULL;

	if (format != NULL)
	{
		va_start(list, format);
		for (i = 0; format[i] != '\0'; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (array[j].symbol == format[i])
				{
					if (sep != NULL)
						printf("%s", sep);
					array[j].func(list);
					sep = ", ";
					break;
				}
			}
		}
		va_end(list);
		printf("\n");
	}
}
