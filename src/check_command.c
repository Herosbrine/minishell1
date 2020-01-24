/*
** EPITECH PROJECT, 2019
** src
** File description:
** check_command.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"

int check_command(char **argv, char **envp, t_data *cordonnee)
{
    cordonnee->y = find_home_path(envp);
    char *envp2 = my_strdup(&envp[cordonnee->y][5]);

    if (my_cd(argv, argv[1], envp2) == 0)
        return (0);
    if (my_unsetenv(argv, argv[1]) == 0)
        return (0);
    my_exit(argv);
    if (my_setenv(argv, argv[1], argv[2], envp) == 0)
        return (0);
    if (parsing_path(argv, argv[0], envp) == 0)
        return (0);
    return (0);
}