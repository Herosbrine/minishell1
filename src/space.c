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

int read_user_input()
{
    size_t sizeb = 1000;
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * sizeb);
    if (getline(&buffer, &sizeb, stdin) == -1)
        return (84);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            buffer[i] = '\0';
    }
    buffer = one_space(buffer);
    my_putstr(buffer);
    return (0);
}

int shell_loop()
{
    int leave = 1;

    while (leave == 1) {
        my_putstr("➜  PSU_minishell1_2019 git:(master) ✗ ");
        read_user_input();
        leave = 0;
    }
    return (0);
}

int main(int ac, char **argv)
{
    if (ac > 1) {
        my_printf("%s: No such file or directory.", argv[1]);
        return (1);
    }
    shell_loop();
    return (0);
}

//main(int ac, char **argv, char **envp)