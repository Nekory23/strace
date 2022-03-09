/*
** EPITECH PROJECT, 2021
** B-PSU_Strace
** File description:
** display_help
*/

#include <stdio.h>
#include "my_strace.h"

int display_help(const char *bin)
{
    printf("USAGE: %s [-s] [-p <pid>|<command>]\n", bin);
    return SUCCESS;
}