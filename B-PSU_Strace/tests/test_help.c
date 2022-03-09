/*
** EPITECH PROJECT, 2021
** B-PSU_Strace
** File description:
** test_help
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_strace.h"

int start(int ac, const char **av, char **env);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_help, return_value, .init=redirect_all_stdout)
{
    const char *av[] = {"./strace", "--help"};

    cr_assert_eq(display_help(av[0]), SUCCESS);
}

Test(display_help, successful_call, .init=redirect_all_stdout)
{
    int ac = 2;
    const char *av[] = {"./strace", "--help"};
    char **env = NULL;

    cr_assert_eq(start(ac, av, env), SUCCESS);
}