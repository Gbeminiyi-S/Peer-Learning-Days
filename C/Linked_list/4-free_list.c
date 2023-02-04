#include "lists.h"

void free_list(list_t *head)
{
	list_t *temp = NULL;

	while (head)
	{
		temp = head;	
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
