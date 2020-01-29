/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** init_struct.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf/my.h"
#include <sys/stat.h>
#include <sys/types.h>

void init_struct(t_data *cordonnee)
{
    cordonnee->r = 1;
    cordonnee->save_pwd = malloc(sizeof(char * ) * 1000);
    save_pwd(cordonnee);
}