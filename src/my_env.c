/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_env.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"

int my_env(char **argv, char **env)
{
    int i = 0;
    char *dest = NULL;

    dest = "env";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 3) == 0) {
            for(int y = 0; env[y] != NULL; y++)
                my_printf("%s\n", env[y]);
            return (0);
        }
        i++;
    }
    return (1);
}