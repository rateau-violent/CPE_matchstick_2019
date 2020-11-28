/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick
*/

#include "matchstick.h"

bool is_end_game(game_t *game)
{
    return (!game->total_matches);
}

int game_loop(game_t *game)
{
    while (game->game_status == 0 || game->game_status == 1) {
        if (game->game_status == 0)
            player(game);
        if (game->game_status == 1)
            ai(game);
    }
    if (game->game_status == 2) {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    if (game->game_status == 3) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    }
    return 0;
}

int matchstick(char **av)
{
    game_t *game = init_game(av);

    if (!game)
        return 84;
    display_map(game);
    return game_loop(game);
}
