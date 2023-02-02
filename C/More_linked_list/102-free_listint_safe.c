#include "lists.h"

size_t free_listint_safe(listint_t **h)
{
	listint_t *tortoise = *h, *hare = *h, *temp = NULL;
	size_t nodes = 0, isLoop = 0;

	if (!(*h))
		return (nodes);

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next, hare = hare->next->next;
		if (tortoise == hare)
		{
			isLoop = 1;
			break;
		}
	}
	
	if (isLoop)
	{
		tortoise = *h;
		while (tortoise != hare)
		{
			tortoise = tortoise->next;
			hare = hare->next;
		}
	}
	/* if linked list is not looped */
	if (!isLoop)
	{
		while (*h)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			nodes++;
		}
	}
	else
		return (looped_free(h, tortoise));
	return (nodes);
}
size_t looped_free(listint_t **h, listint_t *loop_start)
{
	size_t nodes = 0;
	listint_t *temp = NULL;

	while (*h != loop_start)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		nodes++;
	}
	while ((*h)->next != loop_start)
	{	
		temp = (*h)->next;
		free(*h);
		*h = temp;
		nodes++;
	}
	free(*h);
	nodes++;
	return (nodes);
}
