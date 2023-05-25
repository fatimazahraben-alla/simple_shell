#include "c_shell.h"

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
