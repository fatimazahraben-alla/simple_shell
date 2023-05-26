#include "c_shell.h"

/**
 * _strcpy - strcpy func
 * @dest: str
 * @src: str
 * Return: str
 */
char *_strcpy(char *dest, const char *src)
{
	char *s = dest;

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
 * execut_cd - execute cd
 * @td: data struct
 * Return: void
 */
void execut_cd(data *td)
{
	char c_dir[PATH_MAX];
	char n_dir[PATH_MAX];

	if (td->ave[1] == NULL || _strcmp(td->ave[1], "~") == 0)
	{
		_strcpy(n_dir, getenv("HOME"));
	}
	else if (_strcmp(td->ave[1], "-") == 0)
	{
		_strcpy(n_dir, getenv("OLDPWD"));
	}
	else
	{
		_strcpy(n_dir, td->ave[1]);
	}
	if (chdir(n_dir) != 0)
	{
		perror(td->sname);
		return;
	}
	getcwd(c_dir, sizeof(c_dir));
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", c_dir, 1);
}

/**
 * _atoi - atoi func
 * @s: str
 * Return: integer
 */
int _atoi(const char *s)
{
	int res = 0;
	int n = 1;
	int i = 0;

	while (s[i] == ' ' || s[i] == '\t')
	{
		i++;
	}
	if (s[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * n);
}

/**
 * handle_signal - handle_signal
 * @signal: signal
 * Return: void
 */
void handle_signal(__attribute__((unused)) int signal)
{
	printf("\n$ ");
	fflush(stdout);
}

/**
 * _mode - main
 * @td: struct data
 * Return: void
 */
void _mode(data *td)
{
	while (1)
	{
		printf("$ ");
		pr_input(td);
		if (td->cmd[0] == '\0')
			break;
		tokenz_input(td);
		if (td->ave[0])
		{
			if (_strcmp(td->ave[0], "exit") == 0)
				execut_ext(td);
			else if (_strcmp(td->ave[0], "env") == 0)
				execut_envir(td->envir);
			else if (_strcmp(td->ave[0], "cd") == 0)
				execut_cd(td);
			else
				execut_cmd(td);
		} free_toknz(td);
	}
}
