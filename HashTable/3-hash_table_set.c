#include "hash_tables.h"

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *value_copy = NULL, *key_copy = NULL;
	hash_node_t *node = NULL;

	if (!ht || !key)
		return (0);
	
	/* Duplicate the value and key*/
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);


	/* get the index */
	index = key_index((const unsigned char *)key, ht->size);

	/* if the key already exist */
	if (ht->array[index] && *(ht->array[index]->key) == *key)
	{
		free(ht->array[index]->value);
		ht->array[index]->value = value_copy;
		return (1);
	}
	/* if the key did not exist */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		free(value_copy);
		return (0);
	}
	
	key_copy = strdup(key);
	if (key_copy == NULL)
	{
		free(value_copy);
		free(node);
		return (0);
	}


	/* initialising our node */
	node->key = key_copy;
	node->value = value_copy;
	node->next = NULL;

	if (ht->array[index])
	{
		node->next = ht->array[index];
	}
	ht->array[index] = node;

	return (1);
	
}
