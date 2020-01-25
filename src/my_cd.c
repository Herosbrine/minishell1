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

int move_prev_dir(char *buffer)
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

int manage_cd(char *envp, char *envi, char *path)
{
    if (path == NULL) {
        my_str_envp_ar(envp);
        return (0);
    }
    if (chdir(path) == 0)
        return (0);
    if (path[0] == '-') {
        move_prev_dir(envi);
        return (0);
    }
    if (chdir(path) != 0) {
        my_printf("%s: No such file or directory.\n", path);
        return (0);
    }
    return (0);
}

int my_cd(char **argv, char *path, char *envp, char *envi)
{
    int i = 0;
    char *dest = NULL;
    char *pwd = NULL;

    pwd = malloc(sizeof(char) * 100);
    getcwd(pwd, 100);

    dest = "cd";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 2) == 0) {
            if (manage_cd(envp, envi, path) == 0)
                return (0);
        }
        i++;
    }
    return (1);
}