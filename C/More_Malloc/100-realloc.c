#include "main.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	char *old_ptr = ptr;
	unsigned int i;

	if (old_ptr && (new_size > old_size))
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		for (i = 0; i < old_size; i++)
			new_ptr[i] = old_ptr[i];
		free(old_ptr);
	}		
	else if (new_size == old_size)
		return (old_ptr);
	else if (!old_ptr)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
	}
	else if (!new_size && old_ptr)
	{
		free(old_ptr);
		return (NULL);
	}
	return (new_ptr);
}
