/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "printf/my.h"

char *my_strdup(char* str)
{
    char *result = NULL;
    int i = 0;

    result = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i]) {
        result[i] = str[i];
        i++;
    }
    result[i] = 0;
    return (result);
}