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

void parsing_path(char **envp)
{
    int i = find_path(envp);
    int total_word = count_word_envp(envp[i]);

    envp[i] = &envp[i][5];
    envp = my_str_envp_array(&total_word, envp[i]);
}