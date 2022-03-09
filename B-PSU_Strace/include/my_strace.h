/*
** EPITECH PROJECT, 2021
** EpitechTools
** File description:
** main
*/

#ifndef STRACE_H_
#define STRACE_H_

/* INCLUDE */
#include <sys/types.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/user.h>

/* MACRO */
#define SYSCALL_CODE 0x050F

/* STRUCTURE */
typedef struct strace_s
{
    bool is_flag_s;
    bool is_flag_p;
    char **args;
    char **env;
    pid_t c_pid;
    struct user_regs_struct regs;
} strace_t;

/* PROTOTYPES */
int start(int const ac, char const **av, char **env);
int display_help(const char *bin);
bool error_handling(int const ac, char const **av);

int simple_strace(strace_t *st);
void display_syscall(strace_t *st);
int count_env(char **env);
char *get_string(strace_t *st, size_t addr);

/* STATIC CONST */
static const int SUCCESS = 0;
static const int FAIL = 1;
static const int ERROR = 84;

static const long long unsigned int NB_SYSCALL = 328;
static const long long unsigned int EXIT = 231;

#endif /* !STRACE_H_ */
