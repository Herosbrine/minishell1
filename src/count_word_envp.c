/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** count_word_envp.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"

int count_word_envp(char *buffer)
{
    int i = 0;
    int a = 1;

    if (buffer[i] == '\0')
        a = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == ':')
            a++;
        i++;
    }
    return (a);
}