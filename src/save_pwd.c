/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** save_pwd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "printf/my.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int save_pwd(t_data *cordonnee)
{
    char *pwd = NULL;

    pwd = malloc(sizeof(char) * 1000);
    cordonnee->save_pwd[cordonnee->r] = getcwd(pwd, 1000);
    cordonnee->r++;
    return (0);
}