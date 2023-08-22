#include "shell.h"

/**
 * _execute - execute command in parent process then child process
 * @cmd: pointer to a pointer to command array
 * @argv: pointer to a pointer to the argument vector
 * Return: exit status of a child process
 */
int _execute(char **cmd, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			free_array(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_array(cmd);
	}
	return (WEXITSTATUS(status));
}
