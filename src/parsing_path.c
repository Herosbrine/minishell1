/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** space.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int segfault_check(int *status)
{
    if (WIFSIGNALED(*status)) {
        write(2, strsignal(WTERMSIG(*status)),
        my_strlen(strsignal(WTERMSIG(*status))));
        if (WCOREDUMP(*status))
            write(2, " (core dumped)",14);
        if (SIGFPE == *status)
            write(2, "Floating exception (core dumped)", 32);
        if (SIGABRT == *status)
            write(2, "Aborted (core dumped)", 21);
        write(2, "\n", 1);
    }
    return (0);
}

int launch_command(char **argv,  char **env, char *path)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        if (execve(path, argv, env) == -1)
            perror("execve");
        return 1;
    }
    else
        wait(&status);
    segfault_check(&status);
    return 0;
}

int manage_result(int *result, char **all_argv, char **test, char **envp)
{
    for (int y = 0; test[y] != NULL; y++) {
        *result = access(test[y], X_OK);
        if (*result != -1) {
            launch_command(all_argv, envp, test[y]);
            free(test);
            return (0);
        }
    }
    return (1);
}

int parsing_path(char **all_argv, char *argv, char **envp)
{
    int i = find_path(envp), total_word = count_word_envp(envp[i]);
    char **test = NULL;
    char *envp2 = NULL;
    int result = 0;

    envp2 = my_strdup(&envp[i][5]);
    test = my_str_envp_array(&total_word, envp2);
    for (int y = 0; test[y] != NULL; y++)
        my_strcat(test[y], argv);
    if (manage_result(&result, all_argv, test, envp) == 0)
        return (0);
    if (result == -1) {
        if (access(argv, X_OK) == -1)
            my_printf("%s: Command not found.\n", argv);
        else
            launch_command(all_argv, envp, argv);
        return (0);
    }
    return (0);
}