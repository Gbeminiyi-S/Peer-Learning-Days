#include "search_algos.h"

int interpolation_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (ppf(array, 0, size - 1, value));
}

int ppf(int *array, size_t low, size_t high, int value)
{
	size_t pos;

	pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));
	
	if (pos >= low + high)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}

	printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

	if (array[pos] == value)
		return (pos);
	else if (array[pos] > value)
	{
		return ppf(array, low, high - 1, value);
	}
	else
	{
		return ppf(array, low + 1, high, value);
	}

	return (-1);
}
