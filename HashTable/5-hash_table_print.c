#include "hash_tables.h"

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	char *separator = NULL;

	if (ht)
	{
		printf("{");
		while (i < ht->size)
		{
			while (ht->array[i] != NULL)
			{
				if (separator != NULL)
					printf("%s", separator);
				printf("'%s': '%s'", ht->array[i]->key, ht->array[i]->value);
				ht->array[i] = ht->array[i]->next;
				separator = ", ";
			}
			i++;
		}
		printf("}\n");
	}
}
