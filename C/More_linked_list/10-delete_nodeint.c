#include "lists.h"

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev = *head, *present = *head;
	
	if (!(*head))
		return (-1);
	if (!index) /* deleting at the beginning */
	{
		present = (*head)->next;
		free(*head);
		*head = present;
		return (1);
	}
	while (present && index) /* looping to the desired node */
	{
		if (present == NULL) /* index is not in list */
			return (-1);
		prev = present;
		present = present->next;
		index--;
	}
	prev->next = present->next;
	free(present);
	return (1);
}
