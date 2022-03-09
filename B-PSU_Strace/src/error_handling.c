/*
** EPITECH PROJECT, 2021
** strace
** File description:
** error_handling
*/

#include <string.h>
#include <stdio.h>
#include "my_strace.h"

static bool print_error(void)
{
    fprintf(stderr, "./strace: must have PROG [ARGS] or -p PID\n");
    fprintf(stderr, "Try './strace --help' for more information.\n");
    return true;
}

static bool check_flag(char const **av)
{
    if (!strcmp(av[1], "-s") && !av[2]) {
        fprintf(stderr, "./strace: option requires an argument -- 's'\n");
        return true;
    }
    if (!strcmp(av[1], "-p") && !av[2]) {
        fprintf(stderr, "./strace: option requires an argument -- 'p'\n");
        return true;
    }
    if (!strcmp(av[1], "-s") && !strcmp(av[2], "-p") && !av[3]) {
        fprintf(stderr, "./strace: option requires an argument -- 'p'\n");
        return true;
    }
    return false;
}

bool error_handling(int const ac, char const **av)
{
    if (ac < 2)
        return print_error();
    if (!strcmp(av[1], "--help"))
        return false;
    if (check_flag(av))
        return true;
    return false;
}