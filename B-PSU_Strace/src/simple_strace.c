/*
** EPITECH PROJECT, 2021
** B-PSU_Strace
** File description:
** simple_strace
*/

#include <sys/ptrace.h>
#include <sys/wait.h>
#include "my_strace.h"

static bool to_trace(strace_t *st)
{
    if (ptrace(PTRACE_TRACEME, 0, NULL, 0) == -1) {
        perror("ptrace");
        return true;
    }
    if (execvp(st->args[0], &st->args[0]) == -1) {
        perror("execvp");
        return true;
    }
    return false;
}

static bool tracer(strace_t *st)
{
    int status = 0;

    wait(&status);
    if (ptrace(PTRACE_SETOPTIONS, st->c_pid, NULL, PTRACE_O_TRACEEXIT) == -1) {
        perror("ptrace");
        return true;
    }
    while (!WIFEXITED(status)) {
        if (ptrace(PTRACE_GETREGS, st->c_pid, NULL, &st->regs) == -1) {
            perror("ptrace");
            return true;
        }
        display_syscall(st);
        if (ptrace(PTRACE_SINGLESTEP, st->c_pid, NULL, 0) == -1) {
            perror("ptrace");
            return true;
        }
        wait(&status);
    }
    return false;
}

int simple_strace(strace_t *st)
{
    st->c_pid = fork();
    if (st->c_pid == -1)
        return ERROR;
    else if (st->c_pid == 0) {
        if (to_trace(st))
            return ERROR;
    } else
        if (tracer(st))
            return ERROR;
    return SUCCESS;
}