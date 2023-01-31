#include "lists.h"

int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *temp;

	if (!(*head))
		return (data);

	temp = (*head)->next;
	data = (*head)->n;
	free(*head);
	*head = temp;

	return (data);
}
