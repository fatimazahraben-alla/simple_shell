#include "c_shell.h"

/**
 * pr_input - input
 * @td: struct of data
 * Return: void
 */
void pr_input(data *td)
{
	ssize_t read;
	size_t length = 0;

	read = getline(&(td->cmd), &length, stdin);
	if (read == -1)
	{
		td->cmd[0] = '\0';
	}
	else if (td->cmd[read - 1] == '\n')
	{
		td->cmd[read - 1] = '\0';
	}
}

/**
 * tokenz_input - input
 * @td: struct of data
 * Return: void
 */
void tokenz_input(data *td)
{
	const char *delimtrs = " ";
	char *tokn = strtok(td->cmd, delimtrs);
	int n = 0;

	while (tokn)
	{
		td->ave[n] = _strdup(tokn);
		tokn = strtok(NULL, delimtrs);
		n++;
	}
	td->ave[n] = NULL;
}

/**
 * free_toknz - free tokens
 * @td: struct of data
 * Return: void
 */
void free_toknz(data *td)
{
	int i;

	for (i = 0; td->ave[i]; i++)
	{
		free(td->ave[i]);
		td->ave[i] = NULL;
	}
}

/**
 * indata - initi of data
 * @td: struct of data
 * @sname: shell name
 * Return: void
 */
void indata(data *td, const char *sname)
{
	td->cmd = NULL;
	_memset(td->ave, 0, sizeof(td->ave));
	_strncpy(td->sname, sname, sizeof(td->sname) - 1);
	td->envir = NULL;
}

/**
 * free_data - free data
 * @td: struct of data
 * Return:void
 */
void free_data(data *td)
{
	free(td->cmd);
	free_toknz(td);
}
