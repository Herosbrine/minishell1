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
#include <limits.h>

int *new_pwd(char **envp)
{
    int i = 0;
    char *toto = NULL, *save = NULL;
    int a = 0;

    save = malloc(sizeof(char) * 100);
    toto = "PWD=";
    char pwd[PATH_MAX];
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

char *my_str_envp_ar(char *buffer)
{
    int i = 0;
    char *temp = NULL;

    temp = malloc(sizeof(char) * my_strlen(buffer));
    while (buffer[i] != '\0') {
        temp[i] = buffer[i];
        i++;
    }
    chdir(temp);
    return (0);
}

int manage_cd(char **envp, char *envi, char *path)
{
    if (path == NULL || path[0] == '~') {
        my_str_envp_ar(envi);
        new_pwd(envp);
        return (0);
    }
    if (chdir(path) == 0) {
        new_pwd(envp);
        return (0);
    }
    if (chdir(path) != 0) {
        my_printf("%s: No such file or directory.\n", path);
        return (0);
    }
    return (0);
}

int my_cd(char **argv, char **envp, char *envi)
{
    int i = 0;
    char *dest = NULL;

    dest = "cd";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 2) == 0) {
            if (argv[1] != NULL && argv[1][0] == '-') {
                return (0);
            }
            if (manage_cd(envp, envi, argv[1]) == 0)
                return (0);
        }
        i++;
    }
    return (1);
}