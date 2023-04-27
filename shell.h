#ifndef SHELL_H
#define SHELL_H

#define BUFSIZE 1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

void shell_loop(int input);
char **split_string(char *line, char *delimiter);
void get_path(char **cmd);
void execute_command(char **command);
void free_array(char **string_array);
void print_environment(void);
void handle_exit_command(char **cmd, char *line);

#endif
