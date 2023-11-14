#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <time.h>

int main(void);
int print_word(void);
char *add_command(char *directory_path, char *command);
int custom_length(const char *array);
int confirm_built_in_cmd(char **args, int confirm);
int custom_string_compare(char *str1, char *str2);
extern char **environ;
int print_digits(void);
int _putchar(char a);
int parse_input(char *input, char **parsed);
void free_array(char **array, int size);
int check_process(char *pr_name);
int output_prompt(const char *str, unsigned int length);
int error_output(char **c, int add);
void release_last_memory(char *input_cmd);
void print_alphabets(int add);
char *string_dup(char *str);
int string_length(const char *s);
char *check_builtin_cmd(char *str_loc, char *built_cmd);
int execute_process(char **arr);
char *global_environ_cmd(char *env_cmd);
int locate_executable(char **args);

#endif /* SHELL_H */
