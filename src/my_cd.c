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

int my_str_envp_ar(char *buffer)
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

int manage_cd(char **envp, char *envi, char *path, char **argv)
{
    if (path == NULL || path[0] == '~') {
        my_str_envp_ar(envi);
        new_pwd(envp);
        return (0);
    }
    if ((path[0] == '-' && path[1] == 'p' &&
        chdir(argv[2]) == 0) || (path[0] == '-' && path[1] == 'l'&&
        chdir(argv[2]) == 0) || chdir(path) == 0) {
        new_pwd(envp);
        return (0);
    }
    if (chdir(path) != 0) {
        my_printf("%s: No such file or directory.\n", path);
        return (1);
    }
    return (0);
}

int my_cd_prev_dir(t_data *cordonnee)
{
    chdir(cordonnee->save_pwd[cordonnee->r-2]);
    save_pwd(cordonnee);
    return (0);
}

int my_cd(char **argv, char **envp, char *envi, t_data *cordonnee)
{
    int i = 0;
    char *dest = NULL;

    dest = "cd";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 2) == 0) {
            if (argv[1] != NULL && argv[1][0] == '-' && argv[1][1] == '\0') {
                my_cd_prev_dir(cordonnee);
                new_pwd(envp);
                return (0);
            }
            if (manage_cd(envp, envi, argv[1], argv) == 0) {
                save_pwd(cordonnee);
                return (0);
            }
            return (0);
        }
        i++;
    }
    return (1);
}