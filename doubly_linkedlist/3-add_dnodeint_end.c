#include "lists.h"

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp = *head, *new_node = NULL;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return NULL;

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (temp)
	{	
		while (temp->next)
			temp = temp->next;
		
		temp->next = new_node;
		new_node->prev = temp;
	}
	else
		*head = new_node;

	return (new_node);
}
