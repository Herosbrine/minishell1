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

char **read_user_input()
{
    size_t sizeb = 1000;
    char **argv_parsed = NULL;
    char *buffer = NULL;
    char *buffer2 = NULL;

    buffer2 = malloc(sizeof(char) * 1000);
    buffer = malloc(sizeof(char) * 1000);
    if (getline(&buffer, &sizeb, stdin) == -1)
        exit (0);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
    buffer2 = one_space(buffer);
    argv_parsed = count_word(buffer2);
    free(buffer);
    free(buffer2);
    return (argv_parsed);
}