#include "hash_tables.h"

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *value_copy = NULL;

	if (!ht || !key)
		return (0);
	
	/* Duplicated the value */
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

	
}
