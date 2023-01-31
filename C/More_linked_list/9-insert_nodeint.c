#include "lists.h"

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node = NULL, *temp = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	if (!head)
		*head = new_node;
	else
	{
		if (!idx)
		{
			new_node->next = *head;
			*head = new_node;
			return (new_node);
		}
		while (idx != 1)
		{
			if (temp == NULL)
			{
				free(new_node);
				return (NULL);
			}
			temp = temp->next;
			idx--;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	return (new_node);
}
