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

char **position_a(int *a, char *buffer)
{
    int k = 0;
    int i = 0;
    char **a_position = NULL;
    char *temp = NULL;

    a_position =malloc(sizeof(char*) * *a + 1);

    while (i < *a) {
        temp = malloc(sizeof(char) * *a + 1);
        for (; buffer[i] != ' ' && buffer[i] != '\0'; i++) {
            temp[i] = buffer[i];
        }
        a_position[k] = temp;
        k++;
        i++;
        free(temp);
        temp = NULL;
        //buffer[i] = buffer[i+1];
    }
    return (a_position);
}

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

char **read_user_input(char **argv, char **envp)
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
    argv = count_word(buffer);
    for (int i = 0; buffer[i] != ' ' && buffer[i] != '\0'; i++)
        my_putchar(buffer[i]);
    my_putstr(": Command not found.");
    my_putchar('\n');
    return (argv);
}

int shell_loop(char **argv, char **envp)
{
    int leave = 1;

    while (leave == 1) {
        my_putstr("> ");
        read_user_input(argv, envp);
    }
    return (0);
}

int main(int ac, char **argv, char **envp)
{
    if (ac > 1) {
        my_printf("%s: No such file or directory.", argv[1]);
        return (1);
    }
    shell_loop(argv, envp);
    return (0);
}