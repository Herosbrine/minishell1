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

int shell_loop(char **argv, char **envp, t_data *cordonnee)
{
    int leave = 1;

    while (leave == 1) {
        my_putstr("$> ");
        read_user_input(argv, envp, cordonnee);
    }
    return (0);
}