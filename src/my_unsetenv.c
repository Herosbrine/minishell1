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

int my_unsetenv(char **argv, char *path)
{
    int i = 0;
    char *dest = NULL;

    dest = "unsetenv";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 8) == 0) {
            if (path == NULL) {
                my_printf("%s: Too few arguments.\n", dest);
                return (0);
            }
        i++;
        }
        return (1);
    }
    return (1);
}