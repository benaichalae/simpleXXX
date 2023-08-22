#include "shell.h"

/**
 * tokenizer - takes a string and tokenizes it based on a specified delimiter
 * @line: input string
 * Return: allocated array of pointers to strings
 */
char **tokenizer(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int token_count = 0, i;
	int token_size = 1;

	tokens = (char **)malloc(sizeof(char *) * token_size);
	if (tokens == NULL)
		return (NULL);

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[token_count] = _strdup(token);
		if (tokens[token_count] == NULL)
		{
			for (i = 0; i < token_count; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			return (NULL);
		}
		token_count++;
		if (token_count >= token_size)
		{
			token_size *= 2;
		tokens = (char **) _realloc(tokens, sizeof(char *) * token_size,
				sizeof(char *) * token_size);
			if (tokens == NULL)
				return (NULL);
		}
		token = strtok(NULL, DELIM);
	}
	tokens[token_count] = NULL;
	return (tokens);
}
