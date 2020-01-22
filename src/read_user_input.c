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

char **read_user_input(char **argv, char **envp)
{
    size_t sizeb = 1000;
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * sizeb);
    if (getline(&buffer, &sizeb, stdin) == -1)
        exit (84);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
    buffer = one_space(buffer);
    argv = count_word(buffer);
    my_exit(argv);
    for (int i = 0; buffer[i] != ' ' && buffer[i] != '\0'; i++)
        my_putchar(buffer[i]);
    my_putstr(": Command not found.");
    my_putchar('\n');
    return (argv);
}