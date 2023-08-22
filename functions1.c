#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: the source string
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */
char *_strdup(const char *str)
{
	char *c;
	int i, j = 0;

	if (str == NULL)
		return (NULL);
	while (str[j] != '\0')
		j++;
	c = (char *)malloc((sizeof(char) * j) + 1);
	if (c == NULL)
		return (NULL);
	for (i = 0; i < j; i++)
		c[i] = str[i];
	c[j] = '\0';
	return (c);
}
/**
 * _strcmp - compare 2 string
 * @s1:string
 * @s2:strmp
 * Return:int
 */
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}
/**
 * _strcat - concat 2 string
 * @dest:char
 * @src:char
 * Return:char
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strlen - calcule the lenght of a string
 * @s: the char to check
 * Return: i
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	for (; *s++;)
		i++;
	return (i);
}
/**
 * _strcpy - copy the string pointed to by src to dest
 * @dest: char to check
 * @src: char to check
 * Return: 0 is success
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}
