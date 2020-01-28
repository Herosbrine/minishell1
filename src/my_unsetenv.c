/*
** EPITECH PROJECT, 2019
** src
** File description:
** my_cd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "printf/my.h"
#include <stdio.h>

int my_unsetenv2(char **argv, char **envp)
{
    int i = 1;
    int a = 0;
    char *toto = NULL;

    while (argv[i] != NULL) {
        toto = my_strcat2(argv[i], "=");
        while (envp[a] != NULL) {
            if (my_strcmp(envp[a], toto, my_strlen(toto) - 1 ) == 0) {
                envp[a] = NULL;
            }
            a++;
        }
        a = 0;
        i++;
    }
    return (0);
}

int my_unsetenv(char **argv, char **envp)
{
    int i = 0;
    char *dest = NULL;

    dest = "unsetenv";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 8) == 0) {
            if (argv[1] == NULL) {
                my_printf("%s: Too few arguments.\n", dest);
                return (0);
            }
            else
                my_unsetenv2(argv, envp);
            return (0);
        i++;
        }
        return (1);
    }
    return (1);
}