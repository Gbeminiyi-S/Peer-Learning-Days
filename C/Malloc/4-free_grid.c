#include "main.h"

int **alloc_grid(int width, int height)
{
	char **ptr;
	int i, j;

	if (width <= 0 or height <= 0)
		return (NULL);

	ptr = malloc(sizeof(int *) * height);
	if (!ptr)
		return NULL;
	
	for (i = 0; i < height; i++)
	{
		ptr[i] = malloc(sizeof(int) * width);
		if (!ptr[i])
		{
			for (j = 0; j < i; j++)
				free(ptr[j]);
			free(ptr);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			ptr[i][j] = 0;
	}
	return (ptr);
}
