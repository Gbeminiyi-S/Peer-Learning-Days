#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *temp1, *temp2;

	if (*head)
	{
		if ((*head)->next && !index) /*deleting the first node*/
		{
			*head = (*head)->next;
			free((*head)->prev);
			(*head)->prev = NULL;
			return (1);
		}
		if (!((*head)->next) && !index)
		{
			free(*head);
			*head = NULL;
			return (1);
		}
		while(temp && index)
		{
			temp = temp->next;
			index--;
		}
		if (!index)
		{
			temp1 = temp->prev;
			temp2 = temp->next;
			temp1->next = temp2;
			temp2->prev = temp1;
			free(temp);

			return (1);
		}
		if (index)
			return (-1);
	}
	return (-1);
}
