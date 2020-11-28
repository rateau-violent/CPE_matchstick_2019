/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ai
*/

#include "matchstick.h"

void get_params_ai(game_t *game)
{
    game->line = 0;
    while (game->arr_matches[game->line] == 0 && game->line < game->map_size)
        game->line++;
    game->matches = 1;
}

void ai(game_t *game)
{
    my_putstr("\nAI's turn...\n");
    get_params_ai(game);
    my_putstr("AI removed ");
    my_put_nbr(game->matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->line + 1);
    my_putstr("\n");
    update_map(game);
    display_map(game);
    if (is_end_game(game) == true)
        game->game_status = 3;
    else
        game->game_status = 0;
}
