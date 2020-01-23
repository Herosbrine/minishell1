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
#include <sys/types.h>

int launch_command(char **argv,  char **env, char *path)
{
    pid_t pid;
    int status = 0;

    if ((pid = fork()) == -1) {
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
    return 0;
}

int parsing_path(char **all_argv, char *argv, char **envp)
{
    int i = find_path(envp);
    int total_word = count_word_envp(envp[i]);
    char **test = NULL;
    char *envp2 =NULL;
    int result;

    envp2 = my_strdup(&envp[i][5]);
    test = my_str_envp_array(&total_word, envp2);
    for (int y = 0; test[y] != NULL; y++)
        my_strcat(test[y], argv);
    for (int y = 0; test[y] != NULL; y++) {
        result = access(test[y], F_OK);
        if (result != -1) {
            launch_command(all_argv, envp, test[y]);
            return (0);
        }
    }
    return (1);
}