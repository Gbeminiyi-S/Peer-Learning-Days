#include "main.h"

int wordcount(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		for (; str[i] == ' '; i++)
			continue;
		if (str[i])
			count++;
		for (; str[i] != ' ' && str[i]; i++)
			continue;
	}
	return (count);
}
char **strtow(char *str)
{
	char **ptr;
	int size, i = 0, j = 0, k, l, count = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	size = wordcount(str) + 1;
	ptr = malloc(sizeof(char *) * size);
	
	if (!ptr)
		return (NULL);
	while (str[j])
	{
		count = 0;
		for (; str[j] && str[j] == ' '; j++)
			continue;
		k = j;
		for (; str[j] != ' ' && str[j]; j++)
		{
			count++;
		}
		ptr[i] = malloc(sizeof(char) * (count + 1));
		if (!ptr[i])
		{
			for (l = 0; l < i; l++)
			{
				free(ptr[i]);
			}
			free (ptr);
			return (NULL);
		}
		for (l = 0; k < j; l++,k++)
		{
			ptr[i][l] = str[k];
		}
		ptr[i][l] = '\0';
		i++;
	}
	ptr[size - 1] = NULL;
	return (ptr);
}
