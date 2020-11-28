/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_strcmp
*/

#include <stdbool.h>
#include <unistd.h>

int my_strlen(char const *str);

bool my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return false;
    for (size_t i = 0; s1[i]; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}