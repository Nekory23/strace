/*
** EPITECH PROJECT, 2021
** B-PSU_Strace
** File description:
** display_syscall
*/

#include <stdlib.h>
#include "my_strace.h"
#include "syscall_val.h"

static void display_results(strace_t *st)
{
    size_t orig = st->regs.orig_rax;

    if (orig == EXIT || orig == 162) {
        fprintf(stderr, "?\n");
        return;
    }
    if (st->is_flag_s) {
        fprintf(stderr, "%lld\n", st->regs.rax);
        return;
    }
    fprintf(stderr, "0x%llx\n", st->regs.rax);
}

static void display_s(strace_t *st)
{
    size_t regs[6] = {st->regs.rdi, st->regs.rsi, st->regs.rdx,
                        st->regs.rcx, st->regs.r8, st->regs.r9};
    size_t orig = st->regs.orig_rax;
    enum arg_type_e value;
    char *str;
    
    for (int i = 0; i != entries[orig].nb_args; i++) {
        value = entries[orig].args_value[i];
        if (value != NULLVAL && value != STR)
            fprintf(stderr, "%ld", regs[i]);
        else if (value == STR) {
            str = get_string(st, regs[i]);
            fprintf(stderr, "\"%s\"", str);
            free(str);
        }
        if (i != entries[orig].nb_args - 1)
            fprintf(stderr, ", ");
    }
    fprintf(stderr, ") = ");
}

static void display_none(strace_t *st)
{
    size_t regs[6] = {st->regs.rdi, st->regs.rsi, st->regs.rdx,
                        st->regs.rcx, st->regs.r8, st->regs.r9};
    size_t orig = st->regs.orig_rax;

    for (int i = 0; i != entries[orig].nb_args; i++) {
        fprintf(stderr, "0x%lx", regs[i]);
        if (i != entries[orig].nb_args - 1)
            fprintf(stderr, ", ");
    }
    fprintf(stderr, ") = ");
}

static void display_args(strace_t *st)
{
    char *arg = st->args[0];
    int env_nb = count_env(st->env);

    fprintf(stderr, "%s(", entries[st->regs.orig_rax].name);
    if (st->regs.orig_rax == 59) {
        fprintf(stderr, "\"%s\", [\"%s\"], ", arg, arg);
        fprintf(stderr, "[/* %d vars */]) = ", env_nb);
        display_results(st);
        return;
    }
    if (st->is_flag_s)
        display_s(st);
    else
        display_none(st);
    display_results(st);
}

void display_syscall(strace_t *st)
{
    size_t orig = st->regs.orig_rax;

    if ((int)orig == -1)
        return;
    if (orig > NB_SYSCALL) {
        fprintf(stderr, "Unknown\n");
        return;
    }
    display_args(st);
    if (orig == EXIT)
        fprintf(stderr, "+++ exited with %lld +++\n", st->regs.rdi);
}