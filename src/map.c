/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** display map
*/

#include "matchstick.h"

void update_map(game_t *game)
{
    game->arr_matches[game->line] -= game->matches;
    game->total_matches -= game->matches;
}

void first_last_lines(int x)
{
    for (int i = 0; i < x; i++)
        my_putstr("*");
    my_putstr("\n");
}

void display_map(game_t *game)
{
    int x = (game->map_size * 2) + 1;
    int spaces = (x - 3) / 2;

    first_last_lines(x);
    for (int i = 0; i < game->map_size; i++) {
        my_putstr("*");
        for (int j = 0; j < spaces; j++)
            my_putstr(" ");
        for (int j = 0; j < game->arr_matches[i]; j++)
            my_putstr("|");
        for (int j = 0; j < (x - spaces - game->arr_matches[i] - 2); j++)
            my_putstr(" ");
        my_putstr("*\n");
        spaces--;
    }
    first_last_lines(x);
}
