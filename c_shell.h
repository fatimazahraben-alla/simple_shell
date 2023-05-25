#ifndef C_SHELL_H
#define C_SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

#define MAX_CMD_LENGTH 1024

/**
 * struct data - structure
 * @cmd: cmd
 * @ave: ave
 * @sname: shell name
 * @envir: env
 *
 * Description: node structure
 *
 */
typedef struct data
{
	char *cmd;
	char *ave[MAX_CMD_LENGTH];
	char sname[MAX_CMD_LENGTH];
	char **envir;
} data;

size_t _strlen(const char *s, size_t max);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strdup(const char *s);
void *_memset(void *ptr, int v, size_t num);
char *_strncpy(char *dest, const char *src, size_t n);
int _strcmp(const char *s1, const char *s2);
int _atoi(const char *s);

void pr_input(data *td);
void tokenz_input(data *td);
void free_toknz(data *td);
void indata(data *td, const char *sname);
void free_data(data *td);
void handle_signal(__attribute__((unused)) int signal);

void execut_cmd(data *td);
void execut_envir(char **envir);
void execut_ext(data *td);
int main(__attribute__((unused)) int argc, char **argv, char **envir);

#endif
