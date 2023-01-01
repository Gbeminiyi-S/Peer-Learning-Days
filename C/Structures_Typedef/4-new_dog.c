#include "dog.h"

char *_strdup(char *str)
{
	char *str_dup;
	int len, i;

	if (!str)
		return (NULL);
	for (len = 0; str[len]; len++)
		;
	str_dup = malloc(sizeof(char) * (len + 1));
	if (!str_dup)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		str_dup[i] = str[i];
	}
	str_dup[i] = '\0';
	return (str_dup);
}
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (!dog)
		return (NULL);
	dog->name = _strdup(name);
	dog->age = age;
	dog->owner = _strdup(owner);

	if (!(dog->name))
	{
		free(dog);
		return (NULL);
	}
	if (!(dog->owner))
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	return (dog);
}
