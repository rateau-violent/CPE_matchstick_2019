/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** init struct
*/

#include "matchstick.h"

int *get_array(int size)
{
    int *array = malloc(sizeof(int) * (size + 1));

    if (!array)
        return 0;
    for (int i = 0; i < size; i++)
        array[i] = 1 + (i * 2);
    return array;
}

int get_total_sticks(int *arr, int size)
{
    int nb = 0;

    for (int i = 0; i < size; i++)
        nb += arr[i];
    return nb;
}

game_t *init_game(char **av)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->map_size = my_getnbr(av[1]);
    game->max_matches = my_getnbr(av[2]);
    game->arr_matches = get_array(game->map_size);
    game->total_matches = get_total_sticks(game->arr_matches, game->map_size);
    game->game_status = 0;
    game->line = 0;
    game->matches = 0;
    return game;
}
