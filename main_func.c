#include "c_shell.h"

/**
 * _strcmp - strcmp func
 * @s1: str
 * @s2: str
 * Return: int
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/**
 * execut_cmd - command
 * @td: struct data
 * Return: void
 */
void execut_cmd(data *td)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror(td->sname);
		free_data(td);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execvp(td->ave[0], td->ave);
		perror(td->sname);
		free_data(td);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
/**
 * execut_envir - env
 * @envir: env
 * Return: void
 */
void execut_envir(char **envir)
{
	int i;

	for (i = 0; envir[i]; i++)
	{
		printf("%s\n", envir[i]);
	}
}
/**
 * execut_ext - exit
 * @td: struct data
 * Return: void
 */
void execut_ext(data *td)
{
	int status;

	if (td->ave[1] != NULL)
	{
		status = _atoi(td->ave[1]);
		free_data(td);
		exit(status);
	}
	else
	{
		free_data(td);
		exit(EXIT_SUCCESS);
	}
}
/**
 * main - main function
 * @argc: argc
 * @argv: argv
 * @envir: env
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv, char **envir)
{
	data td;
	ssize_t read;
	size_t length = 0;

	indata(&td, argv[0]);
	td.envir = envir;
	signal(SIGINT, handle_signal);
	if (!isatty(STDIN_FILENO))
	{
		while ((read = getline(&(td.cmd), &length, stdin)) != -1)
		{
			if (td.cmd[read - 1] == '\n')
				td.cmd[read - 1] = '\0';
			tokenz_input(&td);
			if (td.ave[0])
				execut_cmd(&td);
			free_toknz(&td);
		}
	} else
	{
		while (1)
		{
			printf("$ ");
			pr_input(&td);
			if (td.cmd[0] == '\0')
				break;
			tokenz_input(&td);
			if (td.ave[0])
			{
				if (_strcmp(td.ave[0], "exit") == 0)
					execut_ext(&td);
				else if (_strcmp(td.ave[0], "env") == 0)
					execut_envir(td.envir);
				else
					execut_cmd(&td);
			} free_toknz(&td);
		}
	}
	free_data(&td);
	return (0);
}
