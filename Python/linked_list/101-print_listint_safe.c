#include "lists.h"

size_t print_listint_safe(const listint_t *head)
{
	int isLoop = 0; /* flag for loop or not */
	const listint_t *tortoise, *hare;
	size_t nodes = 0;

	if (!head)
		exit(98);
	tortoise = head;
	hare = head;

	while (hare && tortoise && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
		{
			isLoop = 1;
			break;
		}
	}

	if (!isLoop)
	{
		while (head)
		{
			printf("[%p] %d\n", head, head->n);
			head = head->next;
			nodes++;
		}
	}
	else
	{
		tortoise = head;
		while(tortoise != hare)
		{
			tortoise = tortoise->next;
			hare = hare->next;
		}
		nodes = looped_printing(head, tortoise);
	}
	return (nodes);
}
size_t looped_printing(const listint_t *head, const listint_t *loop_start)
{
	size_t nodes = 0;

	while (head != loop_start)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nodes++;
	}
	while (head->next != loop_start)
	{		
		printf("[%p] %d\n", (void *)head, head->n);
		nodes++;
		head = head->next;
	}
	printf("[%p] %d\n", (void *)head, head->n);
	nodes++;
	printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);

	return (nodes);
}


