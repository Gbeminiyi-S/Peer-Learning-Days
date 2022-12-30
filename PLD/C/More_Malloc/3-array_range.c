#include "main.h"

int *array_range(int min, int max)
{
	int *ptr;
	int size, i;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	ptr = malloc(sizeof(int) * size);
	if (!ptr)
		return (NULL);
	for (i = 0; i < size; i++, min++)
	{
		ptr[i] = min;
	}
	return (ptr);
}
