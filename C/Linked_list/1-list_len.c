#include "lists.h"

size_t list_len(const list_t *h)
{
	size_t element = 0;

	while (h)
	{
		h =  h->next;
		element++;
	}
	return element;
}
