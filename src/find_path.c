/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** space.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"

int find_path(char **src)
{
    int i = 0;
    char *dest = NULL;

    dest = "PATH=";
    while (src[i] != NULL) {
        if (my_strcmp(src[i], dest, 4) == 0) {
            return (i);
        }
        i++;
    }
    my_putchar('\n');
    return (i);
}

int find_pwd_path(char **src)
{
    int i = 0;
    char *dest = NULL;

    dest = "PWD=";
    while (src[i] != NULL) {
        if (my_strcmp(src[i], dest, 3) == 0) {
            return (i);
        }
        i++;
    }
    my_putchar('\n');
    return (i);
}

int find_home_path(char **src)
{
    int i = 0;
    char *dest = NULL;

    dest = "HOME=";
    while (src[i] != NULL) {
        if (my_strcmp(src[i], dest, 4) == 0) {
            return (i);
        }
        i++;
    }
    my_putchar('\n');
    return (i);
}