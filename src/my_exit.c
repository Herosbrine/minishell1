/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_exit.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"

int my_exit(char **argv)
{
    int i = 0;
    char *dest = NULL;

    dest = "exit";
    while (argv[i] != NULL) {
        if (my_strcmp(argv[i], dest, 4) == 0) {
			exit (0);
        }
        i++;
    }
    return (0);
}