/*
** EPITECH PROJECT, 2021
** B-PSU_Strace
** File description:
** count_env
*/

#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include "my_strace.h"

char *get_string(strace_t *st, size_t addr)
{
    char *buff = malloc(4096);
    int read = 0;
    size_t temp = 0;

    while (42) {
        if (read + sizeof(unsigned long) > 4096)
            buff = realloc(buff, sizeof(buff) * 2);
        temp = ptrace(PTRACE_PEEKDATA, st->c_pid, addr + read);
        if ((int)temp == -1)
            return NULL;
        memcpy(buff + read, &temp, sizeof(unsigned long));
        if (memchr(&temp, 0, sizeof(unsigned long)) != NULL)
            break;
        read += sizeof(unsigned long);
    }
    return buff;
}

int count_env(char **env)
{
    int nbr = 0;

    for (nbr = 0; env[nbr] != NULL; nbr++);
    return nbr;
}