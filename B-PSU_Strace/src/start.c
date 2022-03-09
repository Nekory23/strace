/*
** EPITECH PROJECT, 2021
** B-PSU_Strace
** File description:
** start
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_strace.h"

static void search_flag(strace_t *st, char const **av)
{
    if (!strcmp(av[1], "-s")) {
        st->is_flag_s = true;
        if (!strcmp(av[2], "-p"))
            st->is_flag_p = true;
    }
    else if (!strcmp(av[1], "-p"))
        st->is_flag_p = true;
    else {
        st->is_flag_s = false;
        st->is_flag_p = false;
    }
}

static void get_args(strace_t *st, char const **av, int const ac)
{
    int i = 1;
    int j = 0;

    st->args = malloc(sizeof(char *) * ac + 1);
    if (st->is_flag_s) {
        i++;
        if (st->is_flag_p)
            i++;
    }
    if (st->is_flag_p && !st->is_flag_s)
        i++;
    for (; i != ac; i++, j++)
        st->args[j] = strdup(av[i]);
    st->args[j] = NULL;
}

static void free_struct(strace_t *st)
{
    for (int i = 0; st->args[i] != NULL; i++)
        free(st->args[i]);
    free(st->args);
}

int start(int const ac, char const **av, char **env)
{
    strace_t st;

    if (error_handling(ac, av))
        return ERROR;
    if (!strcmp(av[1], "--help"))
        return display_help(av[0]);
    search_flag(&st, av);
    get_args(&st, av, ac);
    st.env = env;
    if (!st.is_flag_p)
        return (simple_strace(&st));
    free_struct(&st);
    return SUCCESS;
}