#include "shell.h"

/**
 * read_line - reads a line of text from standard input (stdin)
 * Return: line of text read
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t n, input_length;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
	n = getline(&line, &bufsize, stdin);
	if (n == -1 || (n == 0 && line[0] == '\n'))
	{
		free(line);
		return (NULL);
	}
	input_length = _strlen(line);
	if (input_length > 0 && line[input_length - 1] == '\n')
		line[input_length - 1] = '\0';
	return (line);
}
