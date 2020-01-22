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

int main(int ac, char **argv, char **envp)
{
    if (ac > 1) {
        my_printf("%s: No such file or directory.", argv[1]);
        return (1);
    }
    printf("%s\n", envp[find_path(envp)]);
    shell_loop(argv, envp);
    return (0);
}