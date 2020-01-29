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
#include <string.h>

int my_setenv_env1(char *argv, t_data *cordonnee)
{
    int i = 0;
    int a = 0;
    char *toto = my_strcat2(argv, "=");

    while (cordonnee->envp[i] != NULL) {
        if (my_strcmp(cordonnee->envp[i], toto, my_strlen(toto)-1) == 0) {
            a = i;
            cordonnee->envp[a] = my_strdup(argv);
            return (0);
        }
        i++;
    }
    cordonnee->envp[i] = my_strdup(argv);
    cordonnee->envp[i+1] = NULL;
    return (0);
}

int my_setenv_env2(char *argv, char *argv2, t_data *cordonnee)
{
    int i = 0;
    char *argv_mix = NULL;
    char *toto = my_strcat2(argv, "=");
    int a = 0;

    while (cordonnee->envp[i] != NULL) {
        if (my_strcmp(cordonnee->envp[i], toto, my_strlen(toto)-1) == 0) {
            a = i;
            cordonnee->envp[a] = my_strcat2(argv, argv2);
            return (0);
        }
        i++;
    }
    argv_mix = my_strcat2(argv, argv2);
    cordonnee->envp[i] = my_strdup(argv_mix);
    cordonnee->envp[i+1] = NULL;
    return (0);
}

int my_setenv_condition(char **argv, t_data *cordonnee)
{
    if (argv[1] != NULL && argv[2] == NULL) {
        my_setenv_env1(argv[1], cordonnee);
        return (0);
    }
    if (argv[1] != NULL && argv[2] != NULL && argv[3] == NULL) {
        my_setenv_env2(argv[1], argv[2], cordonnee);
        return (0);
    }
    if (argv[1] == NULL) {
        for (int y = 0; cordonnee->envp[y] != NULL; y++)
            my_printf("%s\n", cordonnee->envp[y]);
        return (0);
    }
    else
        my_printf("setenv: Too many arguments.\n");
    return (0);
}

int my_setenv(char **argv, t_data *cordonnee)
{
    int i = 0;
    char *dest = NULL;

    dest = "setenv\0";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 6) == 0) {
            my_setenv_condition(argv, cordonnee);
            return (0);
        }
        i++;
    }
    return (1);
}