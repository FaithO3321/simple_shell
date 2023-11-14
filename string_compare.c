#include "shell.h"
/**
 * custom_string_compare - Function to compare two strings
 * @str1: the first string
 * @str2: the second string
 * Return: 0 if strings are equal
*/
int custom_string_compare(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0'; i++)
	;
	for (i = 0; str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
}

/**
 * string_dup - Function that duplicates a string
 * @str: pointer to the identified string
 * Return: pointer to the duplicated string
*/
char *string_dup(char *str)
{
	char *duplicate;
	unsigned int length, j;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;

	duplicate = malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);

	for (j = 0; j <= length; j++)
		duplicate[j] = str[j];

	return (duplicate);
}

/**
 * string_length - Function to return the string length
 * @s: pointer to the string
 * Return: length of the string
*/
int string_length(const char *s)
{
	int length = 0;

	if (s == NULL)
		return (0);

	while (s[length] != '\0')
		length++;

	return (length++);
}
