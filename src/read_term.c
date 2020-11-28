/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** read term
*/

#include "matchstick.h"

bool is_number(char const *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    for (; str[i]; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n')
            continue;
        return false;
    }
    return true;
}

char *read_term(void)
{
    char *line = NULL;
    size_t len = 0;

    return (getline(&line, &len, stdin) == -1) ? NULL : line;
}
