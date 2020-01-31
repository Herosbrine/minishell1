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

char **my_unsetenv2(char *argv, t_data *cordonnee)
{
    int a = 0, r = 0;
    char *toto = NULL, **save = NULL;

    save = malloc(sizeof(char * ) * 10000);
    toto = my_strcat2(argv, "=");
    for (; cordonnee->envp[a] != NULL; a++, r++) {
        if (my_strcmp(cordonnee->envp[a], toto, my_strlen(toto) - 1 ) == 0) {
            a++;
            if (cordonnee->envp[a] == NULL) {
                r++;
                save[r] = NULL;
                cordonnee->envp = save;
                return (0);
            }
        }
        save[r] = cordonnee->envp[a];
    }
    save[r] = NULL;
    cordonnee->envp = save;
    return (cordonnee->envp);
}

int my_unsetenv_condition(int *y, char *dest, char **argv, t_data *cordonnee)
{
    if (argv[1] == NULL) {
        my_printf("%s: Too few arguments.\n", dest);
        return (0);
    }
    else {
        while (argv[*y] != NULL) {
            my_unsetenv2(argv[*y], cordonnee);
            (*y)++;
        }
        return (0);
    }
    return (0);
}

int my_unsetenv(char **argv)
{
    int i = 0;
    char *dest = NULL;

    dest = "unsetenv";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 8) == 0) {
            return (0);
            i++;
        }
        return (1);
    }
    return (1);
}