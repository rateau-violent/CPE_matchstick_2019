/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "matchstick.h"

int display_help(void)
{
    my_putstr("USAGE\n    ./matchstic nb_lines max_sticks\n");
    return -1;
}

int error_management(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h"))
        return display_help();
    if (ac != 3) {
        my_putstr("Invalid number of arguments\n");
        return 84;
    }
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[2]) < 1) {
        my_putstr("Invalid argument\n");
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    int r = error_management(ac, av);

    if (r)
        return (r == 84) ? r : 0;
    return matchstick(av);
}
