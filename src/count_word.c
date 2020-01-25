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

char **count_word(char *buffer)
{
    int i = 0;
    int a = 1;
    char **argv = NULL;

    if (buffer[i] == '\0')
        a = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == ' ')
            a++;
        i++;
    }
    argv = position_a(&a, buffer);
    return (argv);
}