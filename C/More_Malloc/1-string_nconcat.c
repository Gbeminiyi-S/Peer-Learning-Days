#include "main.h"

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len, size, i = 0, j, k;
	char *ptr;
 
	if (!s2)
		n = 0;
	else
	{
		for (len = 0; s2[len]; len++)
			;

		if (n >= len)
			n = len;
	}
	if (!s1)
		len = 0;
	else
	{
		for (len = 0; s1[len]; len++)
			;
	}
	
	size = len + n + 1;

	ptr = malloc(sizeof(char) * size);

	if (!ptr)
		return (NULL);

	for (j = 0; j < len; j++, i++)
	{
		ptr[i] = s1[j];
	}
	for (k = 0; k < n; k++, i++)
	{
		ptr[i] = s2[k];
	}
	ptr[i] = '\0';
	return (ptr);
}
