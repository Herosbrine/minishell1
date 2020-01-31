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

char **my_str_envp_array(int *a, char *buffer)
{
    int k = 0, i = 0, r = 0;
    char **a_position = NULL;
    char *temp = NULL;

    a_position = malloc(sizeof(char * ) * *a + 1);
    while (r < *a) {
        temp = malloc(sizeof(char) * my_strlen(buffer));
        while (buffer[i] != ':' && buffer[i] != '\0') {
            temp[i] = buffer[i];
            i++;
        }
        buffer = &buffer[i+1];
        a_position[k] = temp;
        i = 0;
        k++;
        r++;
    }
    a_position[k] = NULL;
    return (a_position);
}