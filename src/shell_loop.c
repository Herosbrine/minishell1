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

int shell_loop(char **envp, t_data *cordonnee)
{
    int leave = 1;
    char **argv_parsed = NULL;

    while (leave == 1) {
        my_putstr("$> ");
        argv_parsed = read_user_input();
        check_command(argv_parsed, envp, cordonnee);
        free(argv_parsed);
    }
    return (0);
}