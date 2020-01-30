/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** new_pwd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "printf/my.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int *new_pwd(char **envp)
{
    int i = 0, a = 0;
    char *toto = NULL, *save = NULL;
    char pwd[PATH_MAX];

    save = malloc(sizeof(char) * 100);
    toto = "PWD=";
    getcwd(pwd, sizeof(pwd));
    while (envp[i] != NULL) {
        if (my_strcmp(envp[i], toto, 3) == 0) {
            while (envp[i][a] != '/') {
                save[a] = envp[i][a];
                a++;
            }
            envp[i] = NULL;
            envp[i] = my_strcat2(save, pwd);
        }
        i++;
    }
    return (0);
}