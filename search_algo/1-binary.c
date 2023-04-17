#include "search_algos.h"

void print_array(int *array, size_t low, size_t high)
{
	char *delimiter = NULL;

	printf("Searching in array: ");

	for (; low <= high; low++)
	{
		if (delimiter != NULL)
			printf("%s", delimiter);
		printf("%d", array[low]);
		delimiter = ", ";
	}
	printf("\n");
}

int binary_search(int *array, size_t size, int value)
{
	size_t low = 0, mid, high = size - 1;

	if (!array)
		return (-1);
	/* printing array at the beginning */
	print_array(array, low, high);

	while (low != high)
	{
		mid = (low + high) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
		print_array(array, low, high);
	}
	/* for edge cases */
	if (array[high] == value)
		return (high);
	return (-1);
}
