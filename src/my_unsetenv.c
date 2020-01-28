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

char **my_unsetenv2(char *argv, char **envp)
{
    int a = 0;
    int r = 0;
    char *toto = NULL;
    char **save = NULL;

    save = malloc(sizeof(char*) * 10000);
    toto = my_strcat2(argv, "=");
    while (envp[a] != NULL) {
        if (my_strcmp(envp[a], toto, my_strlen(toto) - 1 ) == 0) {
            a++;
            /*if (envp[a] == NULL) {
                my_printf("env : %s\n", envp[a]);
                r++;
                break;
            }*/
        }
        save[r] = envp[a];
        a++;
        r++;
    }
    save[r] = NULL;
    envp = save;
    return (envp);
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
            else {
                for (int y = 1; argv[y] != NULL; y++)
                    envp = my_unsetenv2(argv[y], envp);
            }
            return (0);
        i++;
        }
        return (1);
    }
    return (1);
}