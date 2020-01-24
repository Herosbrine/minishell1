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
#include <sys/stat.h>
#include <sys/types.h>

int main(int ac, char **argv, char **envp)
{
    t_data cordonnee;
    struct stat info_file;

    if (ac > 1) {
        if (lstat(argv[1], &info_file) == -1) {
            my_printf("%s: No such file or directory.", argv[1]);
            return (1);
        }
        return (0);
    }
    shell_loop(envp, &cordonnee);
    return (0);
}