/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** player
*/

#include "matchstick.h"

int get_line_player(game_t *game)
{
    char *str = NULL;

    my_putstr("Line: ");
    str = read_term();
    if (!str)
        return 1;
    if (!is_number(str)) {
        my_putstr("Error: invalid input (positive number expected)\n");
        get_line_player(game);
        return 0;
    }
    game->line = my_getnbr(str);
    game->line--;
    if (game->line < 0 || game->line > (game->map_size - 1)) {
        my_putstr("Error: this line is out of range\n");
        get_line_player(game);
        return 0;
    }
    return 0;
}

int check_matches_value(game_t *game)
{
    if (game->matches > game->max_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max_matches);
        my_putstr(" matches per turn\n");
        get_matches_player(game);
        return 0;
    }
    if (game->matches < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        get_matches_player(game);
        return 0;
    }
    if (game->matches > game->arr_matches[game->line]) {
        my_putstr("Error: not enough matches matches on this line\n");
        get_matches_player(game);
        return 0;
    }
    return 0;
}

int get_matches_player(game_t *game)
{
    char *str = NULL;

    if (get_line_player(game) == 1)
        return 1;
    game->matches = 0;
    my_putstr("Matches: ");
    str = read_term();
    if (!str)
        return 1;
    if (!is_number(str)) {
        my_putstr("Error: invalid input (positive number expected)\n");
        get_matches_player(game);
        return 0;
    }
    game->matches = my_getnbr(str);
    check_matches_value(game);
    return 0;
}

int player(game_t *game)
{
    my_putstr("\nYour turn:\n");
    if (get_matches_player(game) == 1) {
        game->game_status = 4;
        return 1;
    }
    my_putstr("Player removed ");
    my_put_nbr(game->matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->line + 1);
    my_putstr("\n");
    update_map(game);
    display_map(game);
    game->game_status = (is_end_game(game)) ? 2 : 1;
    return 0;
}
