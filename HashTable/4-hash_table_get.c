#include "hash_tables.h"

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;

	if (!ht || !key)
		return (0);
	
	/* get the index */
	index = key_index((const unsigned char *)key, ht->size);


	while (ht->array[index])
	{
		if (*(ht->array[index]->key) == *key)
			return (ht->array[index]->value);

		ht->array[index] = ht->array[index]->next;
	}

	return (NULL);
}
