#include "c_shell.c"

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
