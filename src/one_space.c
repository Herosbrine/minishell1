/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** one_space.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"

char *delete_last_space(char *save2)
{
    int lenght = my_strlen(save2);
    int a = 0;
    int i = 0;
    char *save = NULL;

    save = malloc(sizeof(char) * my_strlen(save2) + 1);
    if (save2[lenght-1] == ' ')
        lenght--;
    else
        return (save2);
    while (lenght > a) {
        save[a] = save2[i];
        a++;
        i++;
    }
    save[a] = '\0';
    return (save);
}

char *delete_first_space(char *save)
{
    int i = 0;
    int a = 0;
    char *save2 = NULL;

    save2 = malloc(sizeof(char) * my_strlen(save) + 1);
    if (save[i] == ' ')
        i++;
    while (save[i] != '\0') {
        save2[a] = save[i];
        i++;
        a++;
    }
    save2[a] = '\0';
    save2 = delete_last_space(save2);
    return (save2);
}

char *one_space(char *buffer)
{
    int i = 0;
    int a = 0;
    char *save = NULL;

    save = malloc(sizeof(char) * my_strlen(buffer) + 1);
    while (buffer[i] != '\0') {
        if (buffer[i] == ' ') {
            i++;
            if (buffer[i] != ' ') {
                buffer[i-1] = ' ';
                save[a] = buffer[i-1];
                a++;
            }
        } else {
            save[a] = buffer[i];
            a++;
            i++;
        }
    }
    save[a] = '\0';
    buffer = delete_first_space(save);
    return (buffer);
}